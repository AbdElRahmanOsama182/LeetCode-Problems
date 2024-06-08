class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int i = 0, n = word1.size(), m = word2.size();
        string ans = "";
        while(i < n || i < m){
            if (i < n) ans += word1[i];
            if (i < m) ans += word2[i];
            i++;
        }
        return ans;
    }
};