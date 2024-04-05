class Solution {
public:

    void solve(int idx, vector<int> &nums, vector<int> &v, vector<vector<int>> &ans){
        if (v.size() == 3){
            if (v[0] + v[1] + v[2] == 0){
                ans.push_back(v);
            }
            return;
        }
        for (int i = idx; i < nums.size(); i++){
            if (i > idx && nums[i] == nums[i-1]) continue;
            v.push_back(nums[i]);
            solve(i+1, nums, v, ans);
            v.pop_back();
        }
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        vector<int> v;
        solve(0, nums, v, ans);
        return ans;
    }
};