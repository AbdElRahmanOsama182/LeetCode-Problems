class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        unordered_map<int, int> mp;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            mp[nums[i]] = i;
        }
        set<vector<int>> ans;
        vector<int> temp(3);
        for (int i = 0; i < n - 2; i++) {
            for (int j = i + 1; j < n - 1; j++) {
                if (mp.count(0 - nums[i] - nums[j])) {
                    int k = mp[0 - nums[i] - nums[j]];
                    if (i != k && k != j) {
                        temp[0] = nums[i];
                        temp[1] = nums[j];
                        temp[2] = nums[k];
                        sort(temp.begin(), temp.end());
                        ans.insert(temp);
                    }  
                }
            }
        }
        return vector<vector<int>> (ans.begin(), ans.end());
    }
};