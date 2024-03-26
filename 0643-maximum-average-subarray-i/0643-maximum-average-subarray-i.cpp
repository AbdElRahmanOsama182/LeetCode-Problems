class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int sum = 0, maxSum = 0, n = nums.size();
        for (int i = 0; i < k; i++) sum += nums[i];
        maxSum = sum;
        for (int i = k; i < n; i++){
            sum += nums[i] - nums[i - k];
            maxSum = max(maxSum, sum);
        }
        return (double)maxSum / k;
    }
};