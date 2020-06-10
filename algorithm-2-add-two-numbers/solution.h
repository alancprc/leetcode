#pragma once

#include <algorithm>
#include <condition_variable>
#include <functional>
#include <iostream>
#include <list>
#include <vector>

using namespace std;

struct ListNode
{
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(NULL) {}
  // for test only
  ListNode(int x, ListNode* n) : val(x), next(n) {}
};

void printList(ListNode* n)
{
  cout << "list: ";
  while (n != nullptr) {
    cout << n->val << " ";
    n = n->next;
  }
  cout << endl;
}

class Solution
{
 public:
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
  {
    ListNode* head = nullptr;
    auto ptr = head;

    int carry = 0;
    while (l1 != nullptr or l2 != nullptr or carry) {
      int sum = carry;
      if (l1 != nullptr) sum += l1->val;
      if (l2 != nullptr) sum += l2->val;

      if (sum >= 10) {
        carry = 1;
        sum -= 10;
      } else {
        carry = 0;
      }

      ListNode* node = new ListNode(sum);

      if (head == nullptr) {
        ptr = head = node;
      } else {
        ptr->next = node;
        ptr = ptr->next;
      }

      l1 = l1 == nullptr ? nullptr : l1->next;
      l2 = l2 == nullptr ? nullptr : l2->next;
    }
    return head;
  }
};
