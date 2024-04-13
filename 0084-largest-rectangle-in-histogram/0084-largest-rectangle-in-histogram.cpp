class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size(), ans = 0, h, w;
        heights.push_back(0);
        stack<int> s;
        for(int i=0; i<=n; i++){
            while(!s.empty() && heights[s.top()] > heights[i]){
                h = heights[s.top()];
                s.pop();
                w = s.empty() ? i : i - s.top() - 1;
                ans = max(ans, h*w);
            }
            s.push(i);
        }
        return ans;
    }
};