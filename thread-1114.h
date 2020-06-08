#include <atomic>
#include <mutex>
#include <thread>
#include <iostream>
#include <functional>

using namespace std;

void printFirst() { std::cout << "first" << std::endl; }
void printSecond() { std::cout << "second" << std::endl; }
void printThird() { std::cout << "third" << std::endl; }

class Foo
{
 public:
  Foo() { lastNum = 0; }

  void first(function<void()> printFirst)
  {
    while (lastNum.load(std::memory_order_acquire) != 0) {
    }
    // printFirst() outputs "first". Do not change or remove this line.
    printFirst();
    lastNum.store(1, std::memory_order_release);
  }

  void second(function<void()> printSecond)
  {
    // std::lock_guard<std::mutex> lock(mutex_);
    while (lastNum.load(std::memory_order_acquire) != 1) {
    }
    // printSecond() outputs "second". Do not change or remove this line.
    printSecond();
    lastNum.store(2, std::memory_order_release);
  }

  void third(function<void()> printThird)
  {
    // std::lock_guard<std::mutex> lock(mutex_);
    while (lastNum.load(std::memory_order_acquire) != 2) {
    }
    // printThird() outputs "third". Do not change or remove this line.
    printThird();
    lastNum.store(3, std::memory_order_release);
  }

 private:
  std::mutex mutex_;
  std::atomic_int lastNum;
};
