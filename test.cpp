#include <ctype.h>

#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <sstream>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
 public:
  bool hasCycle(ListNode *head) {
    if (head == nullptr) return false;
    ListNode *slow = head;
    ListNode *fast = head->next;
    while (fast != nullptr && slow != nullptr) {
      if (fast == slow) return true;
      slow == slow->next;
      if ((fast = fast->next) == nullptr) return false;
      fast = fast->next;
    }
    return false;
  }
};

void test(void) { Solution s; }