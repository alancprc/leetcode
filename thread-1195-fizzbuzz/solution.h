#pragma once

#include <condition_variable>
#include <functional>
#include <iostream>

using namespace std;

void printFizz() { cout << "fizz"; }
void printBuzz() { cout << "buzz"; }
void printFizzBuzz() { cout << "fizzbuzz"; }
void printNumber(int x) { cout << x; }

class FizzBuzz
{
 private:
  int n;
  int num = 1;
  std::mutex mutex_;
  std::condition_variable cv;

 public:
  FizzBuzz(int n) { this->n = n; }

  // printFizz() outputs "fizz".
  void fizz(function<void()> printFizz)
  {
    while (true) {
      std::unique_lock<std::mutex> lk(mutex_);
      // it's necessary to add condition 'num > n',
      // or the following line 'if (num > n) return;' won't work,
      // thus all threads won't be able to exit.
      cv.wait(lk,
              [this]() { return (num % 3 == 0 and num % 15 != 0) or num > n; });

      if (num > n) return;

      printFizz();

      ++num;
      cv.notify_all();
    }
  }

  // printBuzz() outputs "buzz".
  void buzz(function<void()> printBuzz)
  {
    while (true) {
      std::unique_lock<std::mutex> lk(mutex_);
      cv.wait(lk,
              [this]() { return (num % 5 == 0 and num % 15 != 0) or num > n; });

      if (num > n) return;

      printBuzz();

      ++num;
      cv.notify_all();
    }
  }

  // printFizzBuzz() outputs "fizzbuzz".
  void fizzbuzz(function<void()> printFizzBuzz)
  {
    while (true) {
      std::unique_lock<std::mutex> lk(mutex_);
      cv.wait(lk, [this]() { return num % 15 == 0 or num > n; });

      if (num > n) return;

      printFizzBuzz();

      ++num;
      cv.notify_all();
    }
  }

  // printNumber(x) outputs "x", where x is an integer.
  void number(function<void(int)> printNumber)
  {
    while (true) {
      std::unique_lock<std::mutex> lk(mutex_);
      cv.wait(lk, [this]() { return (num % 3 and num % 5) or num > n; });

      if (num > n) return;

      printNumber(num);

      ++num;
      cv.notify_all();
    }
  }
  void set(int n) { this->n = n; }
};
