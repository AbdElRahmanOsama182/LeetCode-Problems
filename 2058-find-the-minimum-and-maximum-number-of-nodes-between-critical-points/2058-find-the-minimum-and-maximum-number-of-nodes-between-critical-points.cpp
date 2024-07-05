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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> res = {-1, -1};
        int mn = INT_MAX;
        ListNode *prev = head, *curr = head->next;
        int currIdx = 1, prevIdx = 0, criticalIdx = 0;
        while (curr->next) {
            if ((prev->val < curr->val && curr->val > curr->next->val) ||
                (prev->val > curr->val && curr->val < curr->next->val)) {
                if (prevIdx == 0) {
                    prevIdx = currIdx;
                    criticalIdx = currIdx;
                }
                else {
                    mn = min(mn, currIdx - prevIdx);
                    prevIdx = currIdx;
                }
            }
            prev = curr;
            curr = curr->next;
            currIdx++;
        }
        if (mn != INT_MAX) 
            res = {mn, prevIdx - criticalIdx};
        return res;
    }
};