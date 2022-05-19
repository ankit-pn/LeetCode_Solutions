/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast=head,*slow=head,*t=NULL;
        int k=n;
        while(k--){
            fast=fast->next;
        }
        while(fast && slow){
            t=slow;
            slow=slow->next;
            fast=fast->next;
        }
        if(slow==head)
        head=head->next;
        if(t && t->next)
        t->next=t->next->next;
        return head;
    }
};