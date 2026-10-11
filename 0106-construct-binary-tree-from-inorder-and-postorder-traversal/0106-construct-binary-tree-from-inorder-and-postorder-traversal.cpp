#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
private:
    unordered_map<int, int> inorderMap;
    int postorderIndex;

    TreeNode* build(const vector<int>& postorder, int left, int right) {
        if (left > right) {
            return nullptr;
        }

        int rootVal = postorder[postorderIndex--];
        TreeNode* root = new TreeNode(rootVal);

        int mid = inorderMap[rootVal];

        root->right = build(postorder, mid + 1, right);
        root->left = build(postorder, left, mid - 1);

        return root;
    }

public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        postorderIndex = postorder.size() - 1;
        for (int i = 0; i < inorder.size(); i++) {
            inorderMap[inorder[i]] = i;
        }
        return build(postorder, 0, inorder.size() - 1);
    }
};