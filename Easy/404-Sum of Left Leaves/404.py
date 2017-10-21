# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def sumOfLeftLeaves(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        return self.DFS(root, False)
    def DFS(self, root, isLeft):
        
        
        if(not root):
            return 0
        if(not root.left and not root.right):
            return root.val if isLeft else 0
        return self.DFS(root.left, True) + self.DFS(root.right, False)