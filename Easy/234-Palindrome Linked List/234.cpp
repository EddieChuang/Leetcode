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
        
        int size = 0;
        ListNode *tmp = head;
        for(; tmp != NULL; tmp = tmp->next)
            size++;
        
        if(size <= 1)
            return true;
        
        ListNode *rList = reverse(&head, size);
        while(head)
        {
            if(head->val != rList->val)
                return false;
            head = head->next;
            rList = rList->next;
        }
        return true;
    }
    
    ListNode* reverse(ListNode **head, int size)
    {
        int half = size / 2;
        ListNode *prev = NULL, *curr = *head, *next = (*head)->next;
        while(half--)
        {
            curr->next = prev;
            prev = curr;
            curr = next;
            next = next->next;
        }
        *head = size % 2 ? next : curr;
        return prev;
    }
};