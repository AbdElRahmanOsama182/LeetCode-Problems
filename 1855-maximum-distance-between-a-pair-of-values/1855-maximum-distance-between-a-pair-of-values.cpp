class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        int j = 0, i = 0;
        while (i < n && j < m) {
            if (nums1[i] > nums2[j]) i++;
            j++;
        }
        return max(0, j - i - 1);
    }
};