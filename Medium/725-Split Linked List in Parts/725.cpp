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
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        
        int size = getSize(root);
        int n = size / k;  // minimum number of nodes in each group
        int m = size % k;  // extra nodes
        
        vector<ListNode*> res;
        for(int i = 0; i < k; ++i){
            ListNode* subList = getSubList(&root, n, (m--) > 0 ? true : false);
            res.push_back(subList);
        }
        
        return res;
    }
    
    ListNode* getSubList(ListNode **root, int n, bool flag){       
        
        if(!(*root))
            return NULL;
        
        ListNode* subList = new ListNode(0);
        ListNode* curr = subList;
        while(n--){
            curr->next = new ListNode((*root)->val);
            curr = curr->next;
            
            *root = (*root)->next;
        }
        if(flag){
            curr->next = new ListNode((*root)->val);
            curr = curr->next;
            *root = (*root)->next;
        }
        
        return subList->next;
    }
    
    int getSize(ListNode *root){
        
        int size = 0;
        ListNode *node = root;
        while(node){
            node = node->next;
            ++size;
        }
        return size;
    }
    
};
