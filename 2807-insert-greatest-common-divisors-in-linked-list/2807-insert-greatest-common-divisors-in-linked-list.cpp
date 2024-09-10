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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* temp = head;
        while (temp->next) {
            ListNode* GCD = new ListNode(gcd(temp->val, temp->next->val));
            GCD->next = temp->next;
            temp->next = GCD;
            temp = temp->next->next;
        }
        return head;            
    }
};