class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        int i = 0, j = 0, currMedian = 0, prevMedian = 0;
        for (int k = 0; k <= (n+m)/2; k++){
            prevMedian = currMedian;
            if (i != n && j != m){
                if (nums1[i] < nums2[j]) currMedian = nums1[i++];
                else currMedian = nums2[j++];
            }
            else if (i < n) currMedian = nums1[i++];
            else currMedian = nums2[j++];
        }
        if ((n+m)%2 == 0) return (currMedian+prevMedian)/2.0;
        return currMedian;
    }
};