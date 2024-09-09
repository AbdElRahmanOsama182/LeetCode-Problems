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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> ans(m, vector<int>(n, -1));
        vector<int> dir = {0, 1, 0, -1, 0};
        int x = 0, y = 0, d = 0;
        for (; head; head = head->next) {
            ans[x][y] = head->val;
            int nx = x + dir[d], ny = y + dir[d+1];
            if (nx < 0 || nx >= m || ny < 0 || ny >= n || ans[nx][ny] != -1) {
                d = (d+1)%4;
            }
            x += dir[d];
            y += dir[d+1];
        }
        return ans;
    }
};