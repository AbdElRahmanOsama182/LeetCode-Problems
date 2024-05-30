class Solution {
public:
    bool Mirror(TreeNode* left, TreeNode* right){
        if (left == NULL && right == NULL) return true;
        if (left == NULL || right == NULL) return false;
        return (left->val == right->val) && Mirror(left->left, right->right) && Mirror(left->right, right->left);
    }
    bool isSymmetric(TreeNode* root) {
        if (root == NULL) return true;
        return Mirror(root->left, root->right);
    }
};

