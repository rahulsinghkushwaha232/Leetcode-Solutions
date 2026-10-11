class Solution {
private:
    int getLength(ListNode* head) {
        int len = 0;
        while (head != nullptr) {
            len++;
            head = head->next;
        }
        return len;
    }

    TreeNode* buildBST(ListNode*& head, int left, int right) {
        if (left > right) {
            return nullptr;
        }

        int mid = left + (right - left) / 2;
        
        TreeNode* leftChild = buildBST(head, left, mid - 1);
        
        TreeNode* root = new TreeNode(head->val);
        root->left = leftChild;
        
        head = head->next;
        
        root->right = buildBST(head, mid + 1, right);
        
        return root;
    }

public:
    TreeNode* sortedListToBST(ListNode* head) {
        int n = getLength(head);
        return buildBST(head, 0, n - 1);
    }
};