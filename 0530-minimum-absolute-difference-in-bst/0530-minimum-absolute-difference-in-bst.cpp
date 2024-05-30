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
    int getMinimumDifference(TreeNode* root) {
        int ans = INT_MAX;
        TreeNode* prev = NULL;
        inorder(root, prev, ans);
        return ans;
    }

    void inorder(TreeNode* root, TreeNode* &prev, int &ans){
        if(root == NULL) return;
        inorder(root->left, prev, ans);
        if(prev != NULL) ans = min(ans, root->val - prev->val);
        prev = root;
        inorder(root->right, prev, ans);
    }
};