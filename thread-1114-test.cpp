#include "thread-1114.h"
#include <gtest/gtest.h>
#include <future>
#include <iostream>

using namespace std;

class PrintInOrderTest : public ::testing::Test
{
 public:
  void SetUp()
  {
    t3 = std::thread(&Foo::third, &foo, printThird);
    t2 = std::thread(&Foo::second, &foo, printSecond);
    t1 = std::thread(&Foo::first, &foo, printFirst);
  }

 protected:
  Foo foo;
  thread t1;
  thread t2;
  thread t3;
};

TEST_F(PrintInOrderTest, print123)
{
  t1.join();
  t2.join();
  t3.join();
}

TEST_F(PrintInOrderTest, print321)
{
  t3.join();
  t2.join();
  t1.join();
}
