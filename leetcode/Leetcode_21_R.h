#include <iostream>
#include <vector>
using namespace std;

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        if (list1 == nullptr && list2 != nullptr)
            return list2;
        if (list1 != nullptr && list2 == nullptr)
            return list1;

        ListNode *headptr_1 = list1;
        ListNode *headptr_2 = list2;
        ListNode *preNode = nullptr;
        ListNode *head = nullptr;

        // Initialization for the first element
        if (headptr_1 != nullptr && headptr_2 != nullptr)
        {
            if (headptr_1->val < headptr_2->val)
            {
                head = headptr_1;
                preNode = head;
                headptr_1 = headptr_1->next;
            }
            else
            {
                head = headptr_2;
                preNode = head;
                headptr_2 = headptr_2->next;
            }
        }

        // merge loop
        while (headptr_1 != nullptr && headptr_2 != nullptr)
        {
            ListNode *tempptr;
            if (headptr_1->val < headptr_2->val)
            {
                preNode->next = headptr_1;
                preNode = headptr_1;
                headptr_1 = headptr_1->next;
            }
            else
            {
                preNode->next = headptr_2;
                preNode = headptr_2;
                headptr_2 = headptr_2->next;
            }
        }
        if (preNode != nullptr)
        {
            if (headptr_1 == nullptr)
                preNode->next = headptr_2;
            else
                preNode->next = headptr_1;
        }

        return head;
    }
};