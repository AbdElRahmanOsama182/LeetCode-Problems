class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        ListNode *newHead = new ListNode(0);
        ListNode *dummy = new ListNode(0, newHead);
        head = head->next;
        while (head && head->next) {
            if (head->val == 0) {
                newHead->next = new ListNode(0);
                newHead = newHead->next;
            }
            else 
                newHead->val += head->val;
            head = head->next;
        }
        return dummy->next;
    }
};