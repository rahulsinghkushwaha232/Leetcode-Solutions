#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
private:
    unordered_map<int, int> inorderMap;
    int preorderIndex;

    TreeNode* build(const vector<int>& preorder, int left, int right) {
        if (left > right) {
            return nullptr;
        }

        int rootVal = preorder[preorderIndex++];
        TreeNode* root = new TreeNode(rootVal);

        int mid = inorderMap[rootVal];

        root->left = build(preorder, left, mid - 1);
        root->right = build(preorder, mid + 1, right);

        return root;
    }

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        preorderIndex = 0;
        for (int i = 0; i < inorder.size(); i++) {
            inorderMap[inorder[i]] = i;
        }
        return build(preorder, 0, inorder.size() - 1);
    }
};