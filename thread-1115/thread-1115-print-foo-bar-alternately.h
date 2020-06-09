#pragma once

#include <condition_variable>
#include <functional>
#include <iostream>
#include <thread>

using namespace std;

void printFoo() { }//cout << "foo"; }
void printBar() { }//cout << "bar"; }

class FooBar
{
 private:
  int n;
  volatile bool fooDone = false;
  std::mutex mutex_;
  std::condition_variable cvfoo;
  std::condition_variable cvbar;

 public:
  FooBar(int n) { this->n = n; }

  void foo(function<void()> printFoo)
  {
    // why is this necessary? without this, might run into stuck
    std::this_thread::sleep_for(std::chrono::nanoseconds(1));
    for (int i = 0; i < n; i++) {
      std::unique_lock<std::mutex> lk(mutex_);
      // wait for notification
      cvfoo.wait(lk, [this]() { return !fooDone; });
      // printFoo() outputs "foo". Do not change or remove this line.
      printFoo();
      fooDone = true;
      cvbar.notify_all();
    }
  }

  void bar(function<void()> printBar)
  {
    for (int i = 0; i < n; i++) {
      std::unique_lock<std::mutex> lk(mutex_);
      // wait for notification
      cvbar.wait(lk, [this]() { return fooDone; });
      // printBar() outputs "bar". Do not change or remove this line.
      printBar();
      fooDone = false;
      cvfoo.notify_all();
    }
  }

  void set(int n) { this->n = n; }
};
