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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        
        if(!l1 || !l2)
            return l1 ? l1 : l2;
        
        ListNode *newList = new ListNode(0);
        if(l1->val < l2->val)
        {
            newList->val = l1->val;
            newList->next = mergeTwoLists(l1->next, l2);
        }
        else
        {    
            newList->val = l2->val;
            newList->next = mergeTwoLists(l1, l2->next);
        }   
        return newList; 
    }
};