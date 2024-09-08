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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int n = 0;
        ListNode* temp = head;
        while (temp) {
            n++;
            temp = temp->next;
        }
        int size = n/k, rem = n%k;
        cout << size << " " << rem ;
        vector<ListNode*> ans;
        temp = head;
        for (int i = 0; i < k; i++) {
            ListNode* newHead = temp;
            bool extra = i < rem;
            for (int j = 0; j < size + extra - 1; j++) {
                if (temp) temp = temp->next;
            }
            if (newHead) {
                ListNode* prev = temp;
                if (temp) {
                    prev = temp->next;
                    temp->next = nullptr;
                }
                ans.push_back(newHead);
                temp = prev;
            } else {
                ans.push_back(nullptr);
            }
        }
        return ans;
    }
};