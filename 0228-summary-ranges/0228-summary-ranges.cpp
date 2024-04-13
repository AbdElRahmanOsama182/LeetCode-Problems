class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        if (nums.empty()) return {};
        int n = nums.size(), st = 0, ed = 0;
        vector<string> ans;
        for (int i = 1; i < n; i++){
            if(nums[i] == nums[i-1]+1){
                ed = i;
            }else{
                if(st == ed)
                    ans.push_back(to_string(nums[st]));
                else
                    ans.push_back(to_string(nums[st]) + "->" + to_string(nums[ed]));
                st = ed = i;
            }
        }
        if(st == ed)
            ans.push_back(to_string(nums[st]));
        else
            ans.push_back(to_string(nums[st]) + "->" + to_string(nums[ed]));
        return ans;
    }
};