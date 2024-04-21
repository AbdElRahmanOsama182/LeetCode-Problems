class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return n;
        int len = 1, ans =1;
        unordered_set<int> s(nums.begin(),nums.end());
        for (int a:s) {
            if (s.find(a-1) == s.end()) {
                len = 1;
                while (s.find(++a) != s.end())
                    len++;
                ans = max(ans,len);       
            }
        }
        return ans;
    }
};