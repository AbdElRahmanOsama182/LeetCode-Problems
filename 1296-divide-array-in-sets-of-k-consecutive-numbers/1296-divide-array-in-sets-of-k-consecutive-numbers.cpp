class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        int n = nums.size();
        if(n%k != 0) return false;
        unordered_map<int,int> mp;
        for(auto i:nums) mp[i]++;
        for (auto num : nums) {
            int st = num;
            while (mp[st - 1]) st--;
            while (st <= num) {
                while (mp[st]) {
                    for (int i = 0; i < k; i++) 
                        if (!mp[st + i]--) return false;
                }
                st++;
            }
        }
        return true;
    }
};