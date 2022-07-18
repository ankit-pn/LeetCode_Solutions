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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !k)
            return head;
        int c=0;
        ListNode* temp=head;
        while(temp->next){
            c++;
            temp=temp->next;
        }
        c++;
       
        k%=c;
         if(c==1 || k==0)
            return head;
        int len=c-k-1;
        ListNode* curr=head;
        while(len--){
            curr=curr->next;
        }
        ListNode* ans=curr->next;
        curr->next=NULL;
        temp->next=head;
        return ans;
        
    }
};