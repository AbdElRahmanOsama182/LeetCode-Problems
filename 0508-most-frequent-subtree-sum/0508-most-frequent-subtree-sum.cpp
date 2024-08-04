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
    vector<int> findFrequentTreeSum(TreeNode* root) {
        unordered_map<int, int> mp;
        vector<int> ans;
        int maxFreq = 0;
        function<int(TreeNode*)> dfs = [&](TreeNode* node) {
            if (!node) return 0;
            int sum = node->val + dfs(node->left) + dfs(node->right);
            mp[sum]++;
            maxFreq = max(maxFreq, mp[sum]);
            return sum;
        };
        dfs(root);
        for (auto i : mp) {
            if (i.second == maxFreq) ans.push_back(i.first);
        }
        return ans;
    }
};