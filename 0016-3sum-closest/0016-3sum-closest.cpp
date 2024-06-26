class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int ans = 5e4;
        for(int i=0; i<n-2; i++){
            if (i > 0 && nums[i] == nums[i-1]) continue;
            int l = i+1, r = n-1;
            while(l < r){
                int sum = nums[i] + nums[l] + nums[r];
                if (sum == target) return target;
                if (abs(sum - target) < abs(ans - target)) ans = sum;
                if (sum < target) l++;
                else r--;
            }
        }
        return ans;
    }
};