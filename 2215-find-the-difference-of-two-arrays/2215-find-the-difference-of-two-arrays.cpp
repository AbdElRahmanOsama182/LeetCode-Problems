class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> res(2, vector<int>());
        sort(nums1.begin(), nums1.end());
        nums1.resize(distance(nums1.begin(), unique(nums1.begin(), nums1.end())));
        sort(nums2.begin(), nums2.end());
        nums2.resize(distance(nums2.begin(), unique(nums2.begin(), nums2.end())));
        int n = nums1.size(), m = nums2.size(), i = 0, j = 0;
        while (i < n && j < m){
            if (nums1[i] == nums2[j]){
                i++;
                j++;
            }
            else if (nums1[i] < nums2[j]){
                res[0].push_back(nums1[i]);
                i++;
            }
            else{
                res[1].push_back(nums2[j]);
                j++;
            }
        }
        while (i < n){
            res[0].push_back(nums1[i]);
            i++;
        }
        while (j < m){
            res[1].push_back(nums2[j]);
            j++;
        }
        return res;
    }
};