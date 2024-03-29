class Solution {
public:
    int dfs(TreeNode* root, int maxVal){
        if (!root) return 0;
        if (root->val >= maxVal){
            return 1 + dfs(root->left, root->val) + dfs(root->right, root->val);
        }
        return dfs(root->left, maxVal) + dfs(root->right, maxVal);
    }

    int goodNodes(TreeNode* root) {
        return dfs(root, INT_MIN);
    }
};