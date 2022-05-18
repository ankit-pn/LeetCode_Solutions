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
    bool hasCycle(ListNode *head) {
        ListNode *slow=head;
        ListNode *fast=head;
        do {
              if(slow && slow->next)
                slow=slow->next;
            else
                return 0;
            if(fast && fast->next && fast->next->next)
                fast=fast->next->next;
            else
                return 0;
            
        }while(slow!=fast);
        return 1;
        
    }
};