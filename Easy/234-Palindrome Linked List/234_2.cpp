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
    bool isPalindrome(ListNode* head) {
        
        if(!head)
            return true;
        
        ListNode *fast = head;
        ListNode *slow = head;
        while(true)
        {
            fast = fast->next ? fast->next->next : NULL;
            if(!fast)
                break;
            slow = slow->next;            
        }
        ListNode *right = slow->next;
        reverse(&right);
        while(right)
        {
            if(head->val != right->val)
                return false;
            head = head->next;
            right = right->next;
        }
        return true;   
    }
    
    void reverse(ListNode **head)
    {
        ListNode *curr = *head;
        ListNode *prev = NULL;
        while(curr)
        {
            ListNode *tmp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = tmp;
        }
        *head = prev;
    }
};