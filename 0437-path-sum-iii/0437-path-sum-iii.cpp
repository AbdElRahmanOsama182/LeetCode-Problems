class Solution {
public:

    int dfs(TreeNode* root, long targetSum) {
        if (!root) return 0;
        return (root->val == targetSum) + dfs(root->left, targetSum - root->val) + dfs(root->right, targetSum - root->val);
    }

    int pathSum(TreeNode* root, int targetSum) {
        if (!root) return 0;
        return dfs(root, targetSum) + pathSum(root->left, targetSum) + pathSum(root->right, targetSum);
    }
};