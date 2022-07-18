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
    ListNode* mergeNodes(ListNode* head) {
        if(!head->next)
            return NULL;
        ListNode* curr= head->next;
        int sum=0;
        while(curr->val!=0){
            sum+=curr->val;
            curr=curr->next;
        }
        ListNode* temp=mergeNodes(curr);
        ListNode* ans=new ListNode(sum);
        ans->next=temp;
        return ans;
    }
};