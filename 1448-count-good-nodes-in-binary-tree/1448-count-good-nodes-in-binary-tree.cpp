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
    void dfs(TreeNode* root, int maxVal, int &ans){
        if (!root) return;
        if (root->val >= maxVal){
            ans++;
            maxVal = root->val;
        }
        dfs(root->left, maxVal, ans);
        dfs(root->right, maxVal, ans);
    }

    int goodNodes(TreeNode* root) {
        int ans = 0;
        dfs(root, INT_MIN, ans);
        return ans;
    }
};