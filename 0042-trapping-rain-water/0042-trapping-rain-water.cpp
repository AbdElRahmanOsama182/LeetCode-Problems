class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size(), st = 0, ans = 0;
        for (st = 0; st < n; st++){
            if (height[st] != 0) break;
        }
        if (st == n) return 0;
        int sum = 0;
        for (int i = st+1; i < n; i++){
            if (height[i] >= height[st]){
                int h = min(height[i], height[st]);
                ans += (i-st-1)*h - sum;
                sum = 0;
                st = i;
            }
            else{
                int temp = max(0, min(height[st], height[i])*(i-st-1) - sum);
                ans += temp;
                sum += temp;
                sum += height[i];
            }
        }
        return ans;
    }
};