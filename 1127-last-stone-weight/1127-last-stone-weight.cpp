class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for (int i : stones) pq.push(i);
        int a, b;
        while (pq.size() > 1){
            a = pq.top(); pq.pop();
            b = pq.top(); pq.pop();
            if (a != b) pq.push(a - b);
        }
        return pq.empty() ? 0 : pq.top();
    }
};