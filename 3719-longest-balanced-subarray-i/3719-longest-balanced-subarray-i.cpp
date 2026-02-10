class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        for (int l = 0; l < n; l++) {
            auto o = unordered_map<int, int>();
            auto e = unordered_map<int, int>();
            for (int r = l; r < n; r++) {
                auto& c = (nums[r]%2) ? o : e;
                c[nums[r]]++;
                if (e.size() == o.size()) ans = max(ans, r-l+1);
            }
        }
        return ans;
    }
};