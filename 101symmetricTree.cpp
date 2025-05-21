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
    bool isSymmetric(TreeNode* root) {
        return depthFirstSearch(root->left, root->right);
    }
    bool depthFirstSearch(TreeNode* left, TreeNode* right) {
        if (left == nullptr && right == nullptr) return true;
        if (left == nullptr && right != nullptr) return false;
        if (left != nullptr && right == nullptr) return false;

        return left->val == right->val && depthFirstSearch(left->left, right->right)
                                       && depthFirstSearch(left->right, right->left);
    }
};
