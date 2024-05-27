class Solution {
public:
    vector<int> numberGame(vector<int>& nums) {
        priority_queue<int> pq;
        for(auto i : nums) pq.push(i);
        vector<int> ans;
        while(pq.size() > 1){
            int a = pq.top(); pq.pop();
            int b = pq.top(); pq.pop();
            ans.push_back(b);
            ans.push_back(a);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};