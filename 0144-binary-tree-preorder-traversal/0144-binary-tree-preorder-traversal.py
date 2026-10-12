# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def preorderTraversal(self, root):
        result = []
        stack = [root]
        
        while stack:
            curr = stack.pop()
            if curr:
                result.append(curr.val)
                stack.append(curr.right)
                stack.append(curr.left)
                
        return result