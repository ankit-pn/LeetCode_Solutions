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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
       //  ListNode* temp1;
       //  ListNode* temp2;
       //  ListNode* temp3=headB;
       //  while(temp3){
       //      temp2=temp3;
       //      temp1=headA;
       // while(temp1){
       //     if(temp2==temp1){
       //         return temp2;
       //     }
       //        temp1=temp1->next;
       //  }
       //      temp3=temp3->next;
       //  }
       //  return NULL;
        
        // there are two optimal soln present, length and that of two pointer;
        
        ListNode* temp1=headA,*temp2=headB;
        int n=0,m=0;
        while(temp1){
            temp1=temp1->next;
            n++;
        }
        while(temp2){
            temp2=temp2->next;
            m++;
        }
        int diff=abs(n-m);
        while(diff){
            if(n>m){
                headA=headA->next;
                diff--;
            }
            else {
                headB=headB->next;
                diff--;
            }
        }
        while(headA!=NULL && headB!=NULL){
            if(headA==headB)
                return headA;
            headA=headA->next;
            headB=headB->next;
        }
        return NULL;
    }
};