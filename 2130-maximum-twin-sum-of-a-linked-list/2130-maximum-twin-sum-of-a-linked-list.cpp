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
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next = NULL;
        while (curr != NULL){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    int pairSum(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next != NULL && fast->next->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* mid = slow->next;
        slow->next = NULL;
        ListNode* head2 = reverseList(mid);
        int mxSum = 0;
        while (head != NULL && head2 != NULL){
            mxSum = max(mxSum, head->val + head2->val);
            head = head->next;
            head2 = head2->next;
        }
        return mxSum;
    }
};