/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool depthFirstSearch(TreeNode* node, int targetSum, int currentSum) {
        if (!node) return false;

        currentSum += node->val; // alternative approach would be to decrement targetSum til it's equal to 0

        if (!node->left && !node->right) return currentSum == targetSum;

        return depthFirstSearch(node->left, targetSum, currentSum) || 
               depthFirstSearch(node->right, targetSum, currentSum);
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        return depthFirstSearch(root, targetSum, 0);
    }
};
