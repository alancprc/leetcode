#include "thread-1115-print-foo-bar-alternately.h"
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
    t1 = std::thread(&FooBar::foo, &foo, printFoo);
    t2 = std::thread(&FooBar::bar, &foo, printBar);
  }

 protected:
  FooBar foo{1};
  thread t1;
  thread t2;
};

TEST_F(LeetCode, test1)
{
  t1.join();
  t2.join();
}

TEST_F(LeetCode, test10)
{
  foo.set(1e3);
  t2.join();
  std::this_thread::sleep_for(std::chrono::milliseconds(1));
  t1.join();
}
