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
    ListNode* deleteDuplicates(ListNode* head) {
        
        ListNode *curr = head ? head->next : NULL;
        ListNode *last = head;
        for(; curr; curr = curr->next)
        {
            if(curr->val == last->val)
                last->next = curr->next;
            else
                last = last->next;
        }
        return head;
    }
};