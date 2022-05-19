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
        ListNode* temp1;
        ListNode* temp2;
        ListNode* temp3=headB;
        while(temp3){
            temp2=temp3;
            temp1=headA;
       while(temp1){
           if(temp2==temp1){
               return temp2;
           }
              temp1=temp1->next;
        }
            temp3=temp3->next;
        }
        return NULL;
    }
};