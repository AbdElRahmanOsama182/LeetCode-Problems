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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode *temp = head;
        int len = 0;
        while (temp){
            len++;
            temp = temp->next;
        }
        temp = head;
        ListNode *first = NULL, *second = NULL;
        for (int i = 1; i <= len; i++){
            if (i == k){
                first = temp;
            }
            if (i == len - k + 1){
                second = temp;
            }
            temp = temp->next;
        }
        swap(first->val, second->val);
        return head;
    }
};