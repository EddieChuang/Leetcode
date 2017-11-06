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
        
        /*if (!head || !head->next) 
            return false;
        
        ListNode *fast = head->next;
        while (head != fast) 
        {
            if (!fast || !fast->next) 
                return false;
            
            head = head->next;
            fast = fast->next->next;
        }
        return true;*/
        
        
        vector<ListNode*> history;
        
        while(head)
        {
            history.push_back(head);
            head = head->next;
            for(int i = 0; i < history.size(); ++i)
                if(history[i] == head)
                    return true;
        }
        return false;
    }
};