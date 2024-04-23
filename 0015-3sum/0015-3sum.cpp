class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> mp;
    set<vector<int>> res;
        vector<int> temp(3);
        for(int i = 0; i < n; i++) 
            mp[nums[i]] = i;
        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                if (mp.count(0-nums[i]-nums[j])) {
                    int idx = mp[0-nums[i]-nums[j]];
                    if (idx != i && idx != j) {
                        temp[0] = nums[i];
                        temp[1] = nums[j];
                        temp[2] = nums[idx];
                        sort(temp.begin(), temp.end());
                        res.insert(temp);
                    }
                }
            }
        }
        return vector<vector<int>>(res.begin(), res.end());
    }
};