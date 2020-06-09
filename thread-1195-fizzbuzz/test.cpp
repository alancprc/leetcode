#include "solution.h"
#include <gtest/gtest.h>
#include <future>
#include <iostream>
#include <chrono>

using namespace std;

typedef FizzBuzz Foo;

class LeetCode : public ::testing::Test
{
 public:
  void SetUp()
  {
    t1 = std::thread(&Foo::fizz, &foo, printFizz);
    t2 = std::thread(&Foo::buzz, &foo, printBuzz);
    t3 = std::thread(&Foo::fizzbuzz, &foo, printFizzBuzz);
    t4 = std::thread(&Foo::number, &foo, printNumber);
  }

 protected:
  Foo foo{1};
  thread t1;
  thread t2;
  thread t3;
  thread t4;
};

TEST_F(LeetCode, test2)
{
  foo.set(2);
  t1.join();
  t2.join();
  t3.join();
  t4.join();
}

TEST_F(LeetCode, test3)
{
  foo.set(3);
  t1.join();
  t2.join();
  t3.join();
  t4.join();
}

TEST_F(LeetCode, test20)
{
  foo.set(20);
  t1.join();
  t2.join();
  t3.join();
  t4.join();
}

TEST_F(LeetCode, test15)
{
  foo.set(15);
  t4.join();
  t3.join();
  t2.join();
  t1.join();
}
