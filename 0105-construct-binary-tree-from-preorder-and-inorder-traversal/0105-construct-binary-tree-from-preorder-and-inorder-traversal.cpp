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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return build(preorder, inorder, 0, preorder.size()-1, 0, inorder.size()-1);
    }

    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int preSt, int preEn, int inSt, int inEn) {
        if (preSt > preEn || inSt > inEn) return nullptr;
        TreeNode* root = new TreeNode(preorder[preSt]);
        int inRoot = inSt;
        while (inorder[inRoot] != preorder[preSt]) inRoot++;
        int leftSize = inRoot - inSt;
        root->left = build(preorder, inorder, preSt+1, preSt+leftSize, inSt, inRoot-1);
        root->right = build(preorder, inorder, preSt+leftSize+1, preEn, inRoot+1, inEn);
        return root;
    }
};