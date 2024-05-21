class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> sub;
        vector<vector<int>> subs;
        subsets(nums,0, sub, subs);
        return subs;
    }

    void subsets(vector<int>& nums, int i, vector<int>& sub, vector<vector<int>>& subs) {
        subs.push_back(sub);
        for (int j = i; j < nums.size(); j++) {
            sub.push_back(nums[j]);
            subsets(nums, j + 1, sub, subs);
            sub.pop_back();
        }
    }
};