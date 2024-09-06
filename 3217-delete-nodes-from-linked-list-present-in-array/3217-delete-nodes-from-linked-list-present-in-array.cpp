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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++) 
            mp[nums[i]] = i;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;
        while (head) {
            if (mp.find(head->val) != mp.end()) 
                prev->next = head->next;
            else 
                prev = head;
            head = head->next;
        }
        return dummy->next;
    }
};