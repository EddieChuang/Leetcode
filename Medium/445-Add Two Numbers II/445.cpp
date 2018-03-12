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
        
        l1 = reverse(l1);
        l2 = reverse(l2);
        
        ListNode *sum  = new ListNode(0);
        ListNode *curr = sum;
        int carry = 0;
        while(l1 || l2){
            
            int s = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + curr->val;
            curr->val = s % 10;
            
            carry = s / 10;

            l1 = l1 ? l1->next : NULL;
            l2 = l2 ? l2->next : NULL;
            
            curr->next = (l1 || l2 || carry) ? new ListNode(carry) : NULL;
            curr = curr->next ? curr->next : curr;
        }
        return reverse(sum);
    }
    
    ListNode* reverse(ListNode *head){

        ListNode *prev = NULL;
        ListNode *next = NULL;
        while(head){
            next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }
};