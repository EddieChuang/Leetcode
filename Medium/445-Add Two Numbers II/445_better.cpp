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
        
        ListNode *prev = NULL;
        for(int carry = 0, s; l1 || l2 || carry; carry = s / 10){
            
            s = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;
            ListNode* sum = new ListNode(s % 10);
            sum->next = prev;
            prev = sum;
            
            l1 = l1 ? l1->next : NULL;
            l2 = l2 ? l2->next : NULL;
        }
        return prev;
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
    
};