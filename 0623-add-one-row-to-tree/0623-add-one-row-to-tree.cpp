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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (!root) return nullptr;
        if (depth == 1){
            TreeNode* newRoot = new TreeNode(val);
            newRoot->left = root;
            return newRoot;
        }
        if (depth == 2){
            TreeNode* left = new TreeNode(val);
            TreeNode* right = new TreeNode(val);
            left->left = root->left;
            right->right = root->right;
            root->left = left;
            root->right = right;
            return root;
        }
        root->left = addOneRow(root->left, val, depth-1);
        root->right = addOneRow(root->right, val, depth-1);
        return root;
    }
};