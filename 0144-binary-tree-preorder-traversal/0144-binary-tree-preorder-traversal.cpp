class Solution {
public:

    vector<int> tree;

    void preorder(TreeNode* root){
        if(root == NULL) return;
        tree.push_back(root->val);
        preorder(root->left);
        preorder(root->right);
    }

    vector<int> preorderTraversal(TreeNode* root) {
        preorder(root);
        return tree;
    }
};