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
    ListNode* oddEvenList(ListNode* head) {
        ListNode *odd = new ListNode(0);
        ListNode *even = new ListNode(0);
        ListNode *oddHead = odd;
        ListNode *evenHead = even;
        int i = 1;
        while (head){
            if (i%2 == 0){
                even->next = head;
                even = even->next;
            }
            else{
                odd->next = head;
                odd = odd->next;
            }
            head = head->next;
            i++;
        }
        even->next = NULL;
        odd->next = evenHead->next;
        return oddHead->next;
    }
};