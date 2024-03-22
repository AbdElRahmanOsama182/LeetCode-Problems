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
    bool isPalindrome(ListNode* head) {
        ListNode* mid = head;
        ListNode* fast = head;
        while(fast != NULL && fast->next != NULL){
            mid = mid->next;
            fast = fast->next->next;
        }
        mid = reverseList(mid);
        fast = head;
        while (mid != NULL){
            if (mid->val != fast->val){
                return false;
            }
            mid = mid->next;
            fast = fast->next;
        }
        return true;
        
    }
};