class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int idx = n + m - 1, it1 = m - 1, it2 = n - 1;
        while (it1 >= 0 && it2 >=0) {
            if (nums1[it1] > nums2[it2]) {
                nums1[idx--] = nums1[it1--];
            }
            else {
                nums1[idx--] = nums2[it2--];
            }
        }
        while (it2 >= 0) nums1[idx--] = nums2[it2--];
    }
};