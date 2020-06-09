#include "print-zero-even-odd.h"
#include <gtest/gtest.h>
#include <future>
#include <iostream>
#include <chrono>

using namespace std;

class LeetCode : public ::testing::Test
{
 public:
  void SetUp()
  {
    t1 = std::thread(&ZeroEvenOdd::zero, &foo, printNumber);
    t2 = std::thread(&ZeroEvenOdd::odd, &foo, printNumber);
    t3 = std::thread(&ZeroEvenOdd::even, &foo, printNumber);
  }

 protected:
  ZeroEvenOdd foo{1};
  thread t1;
  thread t2;
  thread t3;
};

TEST_F(LeetCode, test2)
{
  foo.set(2);
  t1.join();
  t2.join();
  t3.join();
}

TEST_F(LeetCode, test5)
{
  foo.set(5);
  t3.join();
  t2.join();
  t1.join();
}
