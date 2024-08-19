/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> res;
        stack<pair<int, int>> st;
        for (ListNode* cur = head; cur; cur = cur->next) {
            while (!st.empty() && st.top().first < cur->val) {
                res[st.top().second] = cur->val;
                st.pop();
            }
            st.push({cur->val, res.size()});
            res.push_back(0);
        }
        return res;
    }
};