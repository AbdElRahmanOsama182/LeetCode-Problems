class Solution {
public:
    int minOperations(vector<int>& nums) {
        stack<int> s;
        int ans = 0;
        for (int i: nums) {
            while(!s.empty() && s.top() > i)
                s.pop();
            if (i == 0) continue;
            if (s.empty() || s.top() < i) {
                s.push(i);
                ans++;
            }
        }
        return ans;
    }
};