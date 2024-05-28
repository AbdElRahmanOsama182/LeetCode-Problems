class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.size(), maxLen = 0, cost = 0, st = 0;
        for (int ed = 0; ed < n; ed++){
            cost += abs(s[ed] - t[ed]);
            while (cost > maxCost){
                cost -= abs(s[st] - t[st]);
                st++;
            }
            maxLen = max(maxLen, ed - st + 1);
        }
        return maxLen;            
    }
};