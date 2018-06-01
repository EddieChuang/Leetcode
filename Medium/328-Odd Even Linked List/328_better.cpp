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
    ListNode* oddEvenList(ListNode* head) {
        
        if(!head)
            return NULL;
        ListNode* oddCurr  = head;
        ListNode* evenHead = head->next;
        ListNode* evenCurr = evenHead;

        while(evenCurr && evenCurr->next){
            oddCurr->next = evenCurr->next;

            oddCurr = oddCurr->next;
            evenCurr->next = oddCurr ? oddCurr->next : NULL;  
            evenCurr = evenCurr->next;
        }
        oddCurr->next = evenHead;
        return head;
  
    }

   
};