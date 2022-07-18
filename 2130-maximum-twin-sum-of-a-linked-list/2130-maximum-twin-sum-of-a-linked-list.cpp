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
    int pairSum(ListNode* head) {
        ListNode* slow=head,*fast=head;
        while(fast){
            slow=slow->next;
            fast=fast->next->next;
        }
        // ListNode* curr = reverse(slow);
        int ans1=0;
        vector<int> ans;
        while(slow){
            ans.push_back(slow->val);
            slow=slow->next;
        }      
        ::reverse(ans.begin(),ans.end());
        for(int i=0;i<ans.size();i++){
            ans1=max(ans1,ans[i]+head->val);
            head=head->next;
        }
        return ans1;
    }
    ListNode* reverse(ListNode* head){
        if(!head)
            return NULL;
        if(!head->next)
            return head;
        ListNode* temp = reverse(head->next);
        ListNode* curr=temp;
        while(temp->next)
            temp=temp->next;
        temp->next=head;
        head->next=NULL;
        return curr;
    }
};