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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        int sum = l1->val + l2->val;
        int carry = sum / 10;
        ListNode *head = new ListNode(sum % 10);
        ListNode *curr = head;
                
        l1 = l1->next;
        l2 = l2->next;
        while(l1 || l2 || carry) {

            sum = (l2 ? l2->val : 0) + (l1 ? l1->val : 0) + carry;
            carry = sum / 10;
            
            curr->next = new ListNode(sum % 10);
            curr = curr->next;

            l1 = l1 ? l1->next : NULL;
            l2 = l2 ? l2->next : NULL;
        } 
        
        return head;
    }
};