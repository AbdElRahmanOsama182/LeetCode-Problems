class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int st = 1, ed = arr.size() - 2, mid;
        while (st < ed) {
            mid = st + (ed - st) / 2;
            if (arr[mid] > arr[mid-1] && arr[mid] > arr[mid+1]) {
                return mid;
            }
            if (arr[mid] < arr[mid-1]) {
                ed = mid - 1;
            }
            else {
                st = mid + 1;
            }
        }
        return st;
    }
};