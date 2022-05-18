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
    ListNode* reverseList(ListNode* head) {
      
        if(!head)
            return NULL;
        if(!(head->next))
            return head;
        ListNode* temp=reverseList(head->next);
        ListNode* temp2=temp;
        ListNode* prev=head;
        prev->next=NULL;
        while(temp->next){
            temp=temp->next;
        }
        temp->next=prev;
        return temp2;
        
    }
};