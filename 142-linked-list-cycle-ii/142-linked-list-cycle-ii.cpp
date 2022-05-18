/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow=head;
        ListNode* fast=head;
        ListNode* curr=head;
        do{
            if(slow && slow->next)
                slow=slow->next;
            else
                return NULL;
            if(fast && fast->next && fast->next->next)
                fast=fast->next->next;
            else
                return NULL;
        }
        while(slow!=fast);
        while(curr!=slow){
            curr=curr->next;
            slow=slow->next;
        }
        return curr;
        
    }
};