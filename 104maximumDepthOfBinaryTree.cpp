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
    void findDepth(TreeNode* node, int& depth, int curr) {
        if (!node) return;
        depth = max(depth, curr);
        findDepth(node->left, depth, curr + 1);
        findDepth(node->right, depth, curr + 1);
    }

    int maxDepth(TreeNode* root) {
        int depth = 0;
        findDepth(root, depth, 1);
        return depth;
    }   
};
