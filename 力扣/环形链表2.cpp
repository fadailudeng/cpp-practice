#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };
 

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *p=head,*q=head;
        //int pos=0;
        while(p&&p->next)
        {
            p=p->next->next;
            q=q->next;
            if(p==q)
            {
                ListNode *r=head;
                while(r!=q)
                {
                    r=r->next;
                    q=q->next;
                }
                return r;
            }
        }
        return NULL;
    }
};

int main()
{
    
}
