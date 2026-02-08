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
    int deepestLeavesSum(TreeNode* root) {
        int sum = 0;
        bool dpst = true;
        queue<TreeNode*> q;
        q.push(root);
        while(q.size()) {
            int sz = q.size();
            sum = 0;
            dpst = true;
            for (int i = 0; i < sz; i++) {
                TreeNode* node = q.front();
                q.pop();
                if (node->left) {
                    q.push(node->left);
                    dpst = false;
                }
                if (node->right) {
                    q.push(node->right);
                    dpst = false;
                }
                if (dpst)
                    sum += node->val;
            }
        }
        return sum;
    }
};