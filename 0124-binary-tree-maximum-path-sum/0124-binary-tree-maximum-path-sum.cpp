#include <algorithm>
#include <climits>

using namespace std;

class Solution {
private:
    int maxGain(TreeNode* node, int& maxSum) {
        if (node == nullptr) {
            return 0;
        }

        int leftGain = max(maxGain(node->left, maxSum), 0);
        int rightGain = max(maxGain(node->right, maxSum), 0);

        int currentPathSum = node->val + leftGain + rightGain;

        maxSum = max(maxSum, currentPathSum);

        return node->val + max(leftGain, rightGain);
    }

public:
    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;
        maxGain(root, maxSum);
        return maxSum;
    }
};