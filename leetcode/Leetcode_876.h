#include <iostream>
#include <vector>
#include <string>
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

// 遍历O(n+n/2)
class Solution
{
public:
    ListNode *middleNode(ListNode *head)
    {
        if (head == nullptr)
            return nullptr;
        ListNode *temphead = head;
        int size = 1;
        while (temphead->next != nullptr)
        {
            size++;
            temphead = temphead->next;
        }
        int cnt = 0;
        temphead = head;
        while (cnt < size / 2)
        {
            cnt++;
            temphead = temphead->next;
        }
        return temphead;
    }
};

// 快慢指针
class Solution0
{
public:
    ListNode *middleNode(ListNode *head)
    {
        if (head == nullptr)
            return nullptr;
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast != nullptr && fast != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};

// 变形：如果要返回的是左侧的中间值，快慢指针法该如何实现？
class Solution1
{
public:
    ListNode *middleNode(ListNode *head)
    {
        if (head == nullptr)
            return nullptr;
        ListNode *slow = head;
        ListNode *fast = head;
        ListNode *parentOfslow = nullptr;
        while (fast != nullptr && fast->next != nullptr)
        {
            parentOfslow = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        if (fast == nullptr)
            return parentOfslow;
        else
            return slow;
    }
};
