class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        deque<int> maxQ, minQ;
        int n = nums.size(), ans = 0;
        for (int l = 0, r = 0; r < n; r++) {
            while (!maxQ.empty() && nums[r] > nums[maxQ.back()]) maxQ.pop_back();
            while (!minQ.empty() && nums[r] < nums[minQ.back()]) minQ.pop_back();
            maxQ.push_back(r);
            minQ.push_back(r);
            while (nums[maxQ.front()] - nums[minQ.front()] > limit) {
                if (maxQ.front() == l) maxQ.pop_front();
                if (minQ.front() == l) minQ.pop_front();
                l++;
            }
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};