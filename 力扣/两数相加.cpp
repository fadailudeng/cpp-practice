#include <iostream>
#include <vector>
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head=new ListNode(0);
        ListNode *cur=head;
        int num=0;
        while(l1!=nullptr||l2!=nullptr)
        {
           if(l1==nullptr)
            {
                if(l2->next==nullptr&&l2->val+num>=10)
                {
                    cur->next=new ListNode(l2->val+num-10);
                    cur=cur->next;
                    cur->next=new ListNode(1);
                    break;
                }
                if(l2->val+num>=10)
                {
                    cur->next=new ListNode(l2->val+num-10);
                    num=1;
                }
                else
                {
                    cur->next=new ListNode(l2->val+num);
                    num=0;
                }
                cur=cur->next;
                l2=l2->next;
                continue;
            }
            if(l2==nullptr)
            {
                if(l1->next==nullptr&&l1->val+num>=10)
                {
                    cur->next=new ListNode(l1->val+num-10);
                    cur=cur->next;
                    cur->next=new ListNode(1);
                    break;
                }
                if(l1->val+num>=10)
                {
                    cur->next=new ListNode(l1->val+num-10);
                    num=1;
                }
                else
                {
                    cur->next=new ListNode(l1->val+num);
                    num=0;
                }
                cur=cur->next;
                l1=l1->next;
                continue;
            }
            if(l1->val+l2->val+num>=10)
            {
                cur->next=new ListNode(l1->val+l2->val+num-10);
                num=1;
            }
            else
            {
                cur->next=new ListNode(l1->val+l2->val+num);
                num=0;
            }
            cur=cur->next;
            if(num==1&&l1->next==nullptr&&l2->next==nullptr)
            {
                cur->next=new ListNode(1);
                break;
            }
            if(l1) l1=l1->next;
            if(l2) l2=l2->next;
        }
        return head->next;
    }
};
int main()
{
    ListNode *l1=new ListNode(0);
    ListNode *l2=new ListNode(7);
    l2->next=new ListNode(3);
    Solution s;
    ListNode *res=s.addTwoNumbers(l1,l2);
    while(res!=nullptr)
    {
        cout<<res->val<<" ";
        res=res->next;
    }
}