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
        ListNode *prev = head;
        
        while(curr)
        {
            if(curr->val == prev->val)
                prev->next = curr->next;
            else
                prev = curr;
            curr = curr->next;
        }
        return head;
    }
};