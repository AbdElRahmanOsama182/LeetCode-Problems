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

    void reorderList(ListNode* head) {
        ListNode* mid = head;
        ListNode* fast = head;
        while (fast != NULL && fast->next != NULL){
            mid = mid->next;
            fast = fast->next->next;
        }
        ListNode* rev = reverseList(mid);
        ListNode* curr = head;
        while (rev->next != NULL){
            ListNode* temp = curr->next;
            curr->next = rev;
            rev = rev->next;
            curr->next->next = temp;
            curr = temp;
        }
    }
};