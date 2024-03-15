class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> occur(nums.size()+1, 0), ans(2, 0);
        for(int i=0;i<nums.size();i++) {
            occur[nums[i]]++;
        }
        
        for(int i=1;i<nums.size()+1;i++) {
            if (occur[i]==2) ans[0] = i;
            if (occur[i]==0) ans[1] = i;
        }
        return ans;
    }
};