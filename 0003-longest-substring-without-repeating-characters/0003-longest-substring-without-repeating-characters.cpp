class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<bool> vis(256, false);
        int n = s.size(), ans = 0, st = 0;
        for (int i = 0; i < n; i++){
            while (vis[s[i]]){
                vis[s[st]] = false;
                st++;
            }
            vis[s[i]] = true;
            ans = max(ans, i - st + 1);
        }
        return ans;
    }
};