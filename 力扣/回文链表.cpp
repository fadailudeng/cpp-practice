#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


 // Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) return true;        // 空链 / 单节点，直接算回文

        // ① 快慢指针：slow 最后停在"前半段的最后一个节点"
        ListNode *slow = head, *fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // ② 反转 slow 之后的那半段（就是 LC 206 那套三指针）
        ListNode *prev = nullptr, *cur = slow->next;
        while (cur) {
            ListNode *nxt = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nxt;
        }
        // 此时 prev 是后半段反转后的头

        // ③ 前半段从头走、后半段从 prev 走，逐个比
        ListNode *p = head, *q = prev;
        while (q) {                    // 只判 q：后半段更短或等长
            if (p->val != q->val) return false;
            p = p->next;
            q = q->next;
        }
        return true;
    }
};

int main()
{
    
}