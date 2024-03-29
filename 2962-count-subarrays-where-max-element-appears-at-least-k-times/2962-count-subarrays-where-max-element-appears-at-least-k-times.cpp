class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long long ans = 0;
        int n = nums.size(), st = 0, cnt = 0, mx;
        mx = *max_element(nums.begin(), nums.end());
        for (int i = 0; i < n; i++){
            if (nums[i] == mx) cnt++;
            if (cnt == k){
                ans+=n-i;
                while (nums[st] != mx){
                    ans+=n-i;
                    st++;
                }
                st++;
                cnt--;
            }
        }
        return ans;
    }
};