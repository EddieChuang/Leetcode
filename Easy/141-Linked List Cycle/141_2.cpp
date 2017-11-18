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
        
        ListNode *fast = head ? head->next : NULL;
        ListNode *slow = head;
        
        while(true)
        {
            if(!fast || !slow)
                return false;
            if(fast == slow)
                return true;
            
            if(fast->next)
                fast = fast->next->next;
            else
                fast = NULL;
            slow = slow->next;
        }
        
        
    }
};