# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def isSameTree(self, p, q):
        """
        :type p: TreeNode
        :type q: TreeNode
        :rtype: bool
        """
        if not p or not q:
            return p == q
        elif p.val != q.val:
            return False
        
        left_same  = self.isSameTree(p.left, q.left)
        right_same = self.isSameTree(p.right, q.right)
        
        return left_same and right_same
        
        