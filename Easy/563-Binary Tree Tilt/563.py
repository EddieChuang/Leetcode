# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    
    def findTilt(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        tilt, _ = self.DFS(root)
        return tilt
    
    def DFS(self, root):
        
        if not root:
            return [0, 0]
        
        ltilt, left  = self.DFS(root.left)
        rtilt, right = self.DFS(root.right)
        tilt = abs(left - right) + ltilt + rtilt
        
        return tilt, left + right + root.val