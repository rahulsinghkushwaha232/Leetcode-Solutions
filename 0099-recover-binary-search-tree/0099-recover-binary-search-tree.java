class Solution {
    private TreeNode first = null;
    private TreeNode second = null;
    private TreeNode prev = new TreeNode(Integer.MIN_VALUE);

    public void recoverTree(TreeNode root) {
        traverse(root);
        int temp = first.val;
        first.val = second.val;
        second.val = temp;
    }

    private void traverse(TreeNode node) {
        if (node == null) {
            return;
        }

        traverse(node.left);

        if (first == null && prev.val > node.val) {
            first = prev;
        }
        if (first != null && prev.val > node.val) {
            second = node;
        }
        prev = node;

        traverse(node.right);
    }
}