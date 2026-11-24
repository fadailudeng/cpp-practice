#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

 //Definition for singly-linked list.
 struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
    ListNode *res = nullptr;
    for (ListNode *q = head; q; q = q->next)
    res = new ListNode(q->val, res);   // 插到 res 前面，res 一直往前长
    return res;
    }
};
int main()
{
    
}