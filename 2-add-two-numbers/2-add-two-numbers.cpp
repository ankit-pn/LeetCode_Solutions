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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(!l1)
            return l1;
        if(!l2)
            return l2;
        int f=0;
        int g=0;
        ListNode *h1=l1,*h2=l2;
        ListNode* pre1,*pre2;
        while(l1 || l2){
            int t;
            if(l1 && l2)
            t=l1->val+l2->val+f;
            else if(l1)
                t=l1->val+f;
            
            else{
                t=l2->val+f;
                g=1;
            }
            if(t<10){
                if(l1)
                l1->val=t;
                if(l2)
                l2->val=t;
                f=0;
            }
            else{
                t=t-10;
                if(l1)
                l1->val=t;
                if(l2)
                l2->val=t;
                f=1;
            }
            if(l1){
                pre1=l1;
            l1=l1->next;
            }
            if(l2){
                pre2=l2;
            l2=l2->next;
            }
        }
        if(f==1){
            ListNode* a=new ListNode(1);
            a->next=NULL;
            if(g)
                pre2->next=a;
            else
                pre1->next=a;
                
        }
        if(g)
            return h2;
        else
            return h1;
        
        
        
    }
};