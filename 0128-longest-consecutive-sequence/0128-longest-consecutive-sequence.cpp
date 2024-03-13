class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()<2) return nums.size();
        sort(nums.begin(),nums.end());
        nums.resize(distance(nums.begin(),unique(nums.begin(),nums.end())));
        int le=1,c=1;
        for (int i=1;i<nums.size();i++){
            if(nums[i]==nums[i-1]+1)c++;
            else {
                le=max(le,c);
                c=1;
            }
        }
        le=max(le,c);
        return le;
    }
};