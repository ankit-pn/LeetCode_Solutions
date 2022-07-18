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
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* curr=head,*temp=head;
        int c=0;
        while(curr){
            curr=curr->next;
            c++;
        }
        if(c==1)
            return NULL;
        int x=(c+2)/2;
        x-=2;
        
        while(x>0){
            temp=temp->next;
            x--;
        }
        temp->next=temp->next->next;
        return head;
    }
};