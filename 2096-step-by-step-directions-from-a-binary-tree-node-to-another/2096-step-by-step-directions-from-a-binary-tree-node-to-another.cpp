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
    string getDirections(TreeNode* root, int startValue, int destValue) {
        string startPath, destPath;
        findPath(root, startValue, startPath);
        findPath(root, destValue, destPath);
        int comm = 0;
        while (comm < startPath.length() && comm < destPath.length() && startPath[comm] == destPath[comm])
            comm++;
        string path;
        for (int i = 0; i < startPath.length() - comm; i++)
            path += "U";
        for (int i = comm; i < destPath.length(); i++)
            path += destPath[i];
        return path;        
    }

    bool findPath(TreeNode* root, int value, string& path) {
        if (root == nullptr)
            return false;
        if (root->val == value)
            return true;
        path += 'L';
        if (findPath(root->left, value, path))
            return true;
        path.pop_back();
        path += 'R';
        if (findPath(root->right, value, path))
            return true;
        path.pop_back();
        return false;
    }
};