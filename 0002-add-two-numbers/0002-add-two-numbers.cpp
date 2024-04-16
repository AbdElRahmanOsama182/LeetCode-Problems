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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0, sum = 0;
        ListNode* head = new ListNode();
        ListNode* temp = head;
        while (l1 && l2){
            sum = l1->val + l2->val + carry;
            carry = sum/10;
            sum = sum%10;
            temp->next = new ListNode(sum);
            l1 = l1->next;
            l2 = l2->next;
            temp = temp->next;
        }
        l1 = l1 ? l1 : l2;
        while (l1 && carry){
            sum = l1->val + carry;
            carry = sum/10;
            sum = sum%10;
            temp->next = new ListNode(sum);
            l1 = l1->next;
            temp = temp->next;
        }
        temp->next = l1? l1 : carry ? new ListNode(1) : nullptr;
        return head->next;            
    }
};