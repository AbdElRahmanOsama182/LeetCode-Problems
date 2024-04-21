class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> permute(vector<int>& nums) {
        perm(nums,0,nums.size()-1);
        return ans;
    }
    void perm(vector<int>& nums, int l, int r) {
        if (l==r) {
            ans.push_back(nums);
        }
        else {
            for (int i = l; i <= r; i++)
            {
                swap(nums[l],nums[i]);
                perm(nums,l+1,r);
                swap(nums[l],nums[i]);
            }            
        }
    }
};