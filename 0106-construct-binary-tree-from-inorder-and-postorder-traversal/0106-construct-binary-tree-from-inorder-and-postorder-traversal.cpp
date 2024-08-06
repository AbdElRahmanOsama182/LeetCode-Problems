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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return build(inorder, postorder, 0, inorder.size()-1, 0, postorder.size()-1);
    }

    TreeNode* build(vector<int>& inorder, vector<int>& postorder, int inSt, int inEn, int postSt, int postEn) {
        if (inSt > inEn || postSt > postEn) return nullptr;
        TreeNode* root = new TreeNode(postorder[postEn]);
        int inRoot = inSt;
        while (inorder[inRoot] != postorder[postEn]) inRoot++;
        int leftSize = inRoot - inSt;
        root->left = build(inorder, postorder, inSt, inRoot-1, postSt, postSt+leftSize-1);
        root->right = build(inorder, postorder, inRoot+1, inEn, postSt+leftSize, postEn-1);
        return root;
    }
};