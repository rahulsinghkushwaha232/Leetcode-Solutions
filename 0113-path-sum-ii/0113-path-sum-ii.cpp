#include <vector>

using namespace std;

class Solution {
private:
    void dfs(TreeNode* node, int targetSum, vector<int>& currentPath, vector<vector<int>>& result) {
        if (node == nullptr) {
            return;
        }

        currentPath.push_back(node->val);

        if (node->left == nullptr && node->right == nullptr && targetSum == node->val) {
            result.push_back(currentPath);
        } else {
            dfs(node->left, targetSum - node->val, currentPath, result);
            dfs(node->right, targetSum - node->val, currentPath, result);
        }

        currentPath.pop_back();
    }

public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> result;
        vector<int> currentPath;
        dfs(root, targetSum, currentPath, result);
        return result;
    }
};