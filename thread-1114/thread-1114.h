#include <atomic>
#include <iostream>
#include <thread>

using namespace std;

void printFirst() { std::cout << "first" << std::endl; }
void printSecond() { std::cout << "second" << std::endl; }
void printThird() { std::cout << "third" << std::endl; }

class Foo
{
 public:
  Foo()
  {
    firstDone.test_and_set(std::memory_order_acquire);
    secondDone.test_and_set(std::memory_order_acquire);
  }

  void first(function<void()> printFirst)
  {
    // printFirst() outputs "first". Do not change or remove this line.
    printFirst();
    firstDone.clear(std::memory_order_release);
  }

  void second(function<void()> printSecond)
  {
    while (firstDone.test_and_set(std::memory_order_acquire))
      ;
    // printSecond() outputs "second". Do not change or remove this line.
    printSecond();
    secondDone.clear(std::memory_order_release);
  }

  void third(function<void()> printThird)
  {
    while (secondDone.test_and_set(std::memory_order_acquire))
      ;
    // printThird() outputs "third". Do not change or remove this line.
    printThird();
  }

 private:
  std::atomic_flag firstDone = ATOMIC_FLAG_INIT;
  std::atomic_flag secondDone = ATOMIC_FLAG_INIT;
};
