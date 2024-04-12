class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size(), l = 0, r = n-1, mxL = 0, mxR = 0, ans = 0;
        while (l <= r){
            if (height[l] <= height[r]){
                if (height[l] >= mxL) mxL = height[l];
                else ans += mxL - height[l];
                l++;
            }
            else{
                if (height[r] >= mxR) mxR = height[r];
                else ans += mxR - height[r];
                r--;
            }
        }
        return ans;
    }
};