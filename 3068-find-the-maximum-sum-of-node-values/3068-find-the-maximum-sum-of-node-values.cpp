class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        long long sum = 0;
        int cnt  = 0, pos = INT_MAX, neg = INT_MIN;
        for (int num : nums) {
            sum += num;
            int diff = (num ^ k) - num;
            if (diff > 0) {
                pos = min(pos, diff);
                sum += diff;
                cnt++;
            }
            else 
                neg = max(neg, diff);
        }
        if (cnt % 2 == 0)
            return sum;
        return max(sum - pos, sum + neg);
    }
};