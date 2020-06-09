#pragma once

#include <condition_variable>
#include <iostream>
#include <mutex>
#include <thread>

using namespace std;

void printFirst() { std::cout << "first" << std::endl; }
void printSecond() { std::cout << "second" << std::endl; }
void printThird() { std::cout << "third" << std::endl; }

class Foo
{
 public:
  Foo() {}

  void first(function<void()> printFirst)
  {
    // 等待直至 main() 发送数据
    std::unique_lock<std::mutex> lk(g_mutex);
    // printFirst() outputs "first". Do not change or remove this line.
    printFirst();
    // 通知前完成手动解锁，以避免等待线程才被唤醒就阻塞（细节见 notify_one ）
    counter++;
    cv1.notify_one();
  }

  void second(function<void()> printSecond)
  {
    std::unique_lock<std::mutex> lk(g_mutex);
    cv1.wait(lk, [this]() { return counter == 2; });  // 阻塞当前线程，直到条件变量被唤醒
    // printSecond() outputs "second". Do not change or remove this line.
    printSecond();
    counter++;
    cv2.notify_one();
  }

  void third(function<void()> printThird)
  {
    std::unique_lock<std::mutex> lk(g_mutex);
    cv2.wait(lk, [this]() { return counter == 3; });
    // printThird() outputs "third". Do not change or remove this line.
    printThird();
  }

 private:
  int counter = 1;
  std::condition_variable cv1;
  std::condition_variable cv2;
  // 使用lock和unlock手动加锁
  std::mutex g_mutex;
};

/*
作者：georgeC 链接：https://leetcode-cn.com/problems/print-in-order/solution/cpp-beats-100-shi-yong-tiao-jian-bian-liang-by-geo/
来源：力扣（LeetCode） 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/
