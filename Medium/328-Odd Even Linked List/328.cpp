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

        ListNode* odd  = getSubList(head);
        ListNode* even = getSubList(head->next);
        ListNode* curr = odd;
        while(curr->next)
                curr = curr->next;
        curr->next = even;
        return odd;
    }

    ListNode* getSubList(ListNode* head){

        ListNode* subList = new ListNode(0);
        ListNode* current = subList;
        while(head){
            current->next = new ListNode(head->val);
            current = current->next;
            head = head->next ? head->next->next : NULL;
        }
        return subList->next;
    }
};


