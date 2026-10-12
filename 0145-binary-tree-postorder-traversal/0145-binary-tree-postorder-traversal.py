class Solution:
    def postorderTraversal(self, root):
        if not root:
            return []
            
        stack = [root]
        result = []
        
        while stack:
            curr = stack.pop()
            result.append(curr.val)
            if curr.left:
                stack.append(curr.left)
            if curr.right:
                stack.append(curr.right)
                
        return result[::-1]