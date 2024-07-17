class Solution {
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_set<int> toDelete(to_delete.begin(), to_delete.end());
        vector<TreeNode*> forest;
        root = delNodes(root, toDelete, forest);
        if (root)
            forest.push_back(root);
        return forest;
    }

    TreeNode* delNodes(TreeNode* root, unordered_set<int>& toDelete, vector<TreeNode*>& forest) {
        if (!root)
            return nullptr;
        root->left = delNodes(root->left, toDelete, forest);
        root->right = delNodes(root->right, toDelete, forest);
        if (toDelete.count(root->val)) {
            if (root->left)
                forest.push_back(root->left);
            if (root->right)
                forest.push_back(root->right);
            return nullptr;
        }
        return root;
    }
};