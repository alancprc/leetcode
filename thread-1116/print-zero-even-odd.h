#pragma once

#include <condition_variable>
#include <functional>
#include <iostream>
#include <thread>

using namespace std;

void printNumber(int x) { cout << x; }

class ZeroEvenOdd
{
 private:
  int n;
  int counter;
  bool printZero{true};
  std::mutex mutex_;
  std::condition_variable cv;

 public:
  ZeroEvenOdd(int n)
  {
    this->n = n;
    printZero = true;
    counter = 1;
  }

  // printNumber(x) outputs "x", where x is an integer.
  void zero(function<void(int)> printNumber)
  {
    for (int i = 0; i < n; ++i) {
      std::unique_lock<std::mutex> lk(mutex_);
      cv.wait(lk, [this]() { return printZero; });
      printNumber(0);

      printZero = false;
      cv.notify_all();
    }
  }

  void even(function<void(int)> printNumber)
  {
    for (int i = 2; i <= n; i += 2) {
      std::unique_lock<std::mutex> lk(mutex_);
      cv.wait(lk, [this]() { return !printZero and !(counter & 0x1); });
      printNumber(i);

      counter++;
      printZero = true;
      cv.notify_all();
    }
  }

  void odd(function<void(int)> printNumber)
  {
    for (int i = 1; i <= n; i += 2) {
      std::unique_lock<std::mutex> lk(mutex_);
      cv.wait(lk, [this]() { return !printZero and (counter & 0x1); });
      printNumber(i);

      counter++;
      printZero = true;
      cv.notify_all();
    }
  }

  void set(int n) { this->n = n; }
};
