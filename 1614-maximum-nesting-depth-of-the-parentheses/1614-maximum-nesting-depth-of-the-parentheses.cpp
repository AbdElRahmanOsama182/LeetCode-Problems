class Solution {
public:
    int maxDepth(string s) {
        int cnt = 0, mx = 0;
        for(auto i:s){
            if(i == '(') cnt++;
            else if(i == ')') {
                mx = max(mx, cnt);
                cnt--;
            }
        }
        return mx=max(mx, cnt);
    }
};