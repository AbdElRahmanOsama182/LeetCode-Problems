/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (p->val < q->val) {
            return LCA(root, p->val, q->val);
        }
        return LCA(root, q->val, p->val);
    }

    TreeNode* LCA(TreeNode* root, int mn, int mx) {
        if (root->val > mx) {
            return LCA(root->left, mn, mx);
        }
        if (root->val < mn) {
            return LCA(root->right, mn, mx);
        }
        return root;
    }
};