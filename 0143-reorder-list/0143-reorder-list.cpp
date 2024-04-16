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
    void reorderList(ListNode* head) {
        if (!head || !head->next) return;
        ListNode* slow = head, *fast = head->next;
        while (fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* second = slow->next;
        slow->next = nullptr;
        ListNode* prev = nullptr;
        ListNode* next = nullptr;
        while (second){
            next = second->next;
            second->next = prev;
            prev = second;
            second = next;
        }
        second = prev;
        ListNode* first = head;
        while (first && second){
            ListNode* fNext = first->next;
            ListNode* sNext = second->next;
            first->next = second;
            second->next = fNext;
            first = fNext;
            second = sNext;
        }
    }
};