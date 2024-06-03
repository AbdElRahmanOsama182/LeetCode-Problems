/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> mp;
        Node* temp = head;
        while(temp){
            if (!mp.count(temp))
                mp[temp] = new Node(temp->val);
            if (temp->next){
                if (!mp.count(temp->next))
                    mp[temp->next] = new Node(temp->next->val);
                mp[temp]->next = mp[temp->next];
            }
            if (temp->random){
                if (!mp.count(temp->random))
                    mp[temp->random] = new Node(temp->random->val);
                mp[temp]->random = mp[temp->random];
            }
            temp = temp->next;
        }
        return mp[head];
    }
};