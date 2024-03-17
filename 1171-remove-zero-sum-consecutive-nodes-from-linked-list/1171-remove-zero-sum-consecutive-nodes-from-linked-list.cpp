class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        unordered_map<int, ListNode*> m;
        int prefix = 0;
        for (ListNode* i = dummy; i != nullptr; i = i->next) {
            prefix += i->val;
            m[prefix] = i;
        }
        prefix = 0;
        for (ListNode* i = dummy; i != nullptr; i = i->next) {
            prefix += i->val;
            i->next = m[prefix]->next;
        }
        return dummy->next;
    }
};