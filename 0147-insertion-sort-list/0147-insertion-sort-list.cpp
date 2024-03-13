class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode* start = new ListNode(0);
        start->next = head;
        ListNode* prev = head;
        ListNode* curr = head->next;
        while(curr != nullptr){
            if (curr->val >= prev->val){
                prev = curr;
                curr = curr->next;
            }
            else{
                ListNode* temp = start;
                while(temp->next->val <= curr->val)
                    temp = temp->next;
                prev->next = curr->next;
                curr->next = temp->next;
                temp->next = curr;
                curr = prev->next;
            }
        }
        return start->next;
    }
};