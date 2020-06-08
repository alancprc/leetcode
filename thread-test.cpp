#include <atomic>
#include <future>
#include <iostream>
#include <thread>
#include <vector>

using namespace std;

vector<int> mySharedWork;
atomic<bool> dataProduced(false);
atomic<bool> dataConsumed(false);

void dataProducer() 
{
  mySharedWork = {1, 0, 3};
  dataProduced.store(true, std::memory_order_release);
}

void deliverBoy()
{
  while (!dataProduced.load(std::memory_order_acquire))
    ;
  dataConsumed.store(true, std::memory_order_release);
}

void dataConsumer()
{
  while (!dataConsumed.load(std::memory_order_acquire))
    ;
  mySharedWork[1] = 2;
}

int main()
{
  thread t1(dataConsumer);
  thread t2(deliverBoy);
  thread t3(dataProducer);
  t1.join();
  t2.join();
  t3.join();
  // auto f1 = std::async(dataConsumer);
  // auto f2 = std::async(deliverBoy);
  // auto f3 = std::async(dataProducer);

  for (auto& e : mySharedWork) {
    std::cout << e << " ";
  }
  std::cout << std::endl;
  return 0;
}
