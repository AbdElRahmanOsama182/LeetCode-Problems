class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> mp;
        for (auto i: nums) mp[i]++;
        int mx = 0, ans = 0;
        for (auto i: mp){
            if (i.second > mx){
                mx = i.second;
                ans = i.first;
            }
        }
        return ans;
    }
};