class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        
        value = root->val;
        DFS(root, 0, 0);
        return value;
    }
    
    void DFS(TreeNode *root, int x, int y){
        
        if(!root)
            return;

        if(y > yPos){
            value = root->val;
            yPos = y;
        }
        if(y == yPos && x < xPos){
            value = root->val;
            xPos = x;
        }

        DFS(root->left, x-1, y+1);
        DFS(root->right, x+1, y+1);
    }
    
private:
    
    int xPos = 0;
    int yPos = 0;
    int value;
    
};