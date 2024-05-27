class Solution {
public:
    int specialArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> freq(n + 32, 0);
        for (int& num : nums) freq[min(n, num)]++;
        for (int i = n; i > -1; i--) {
            freq[i] += freq[i + 1];
            if (freq[i] == i) return i;
        }
        return -1;
    }
};