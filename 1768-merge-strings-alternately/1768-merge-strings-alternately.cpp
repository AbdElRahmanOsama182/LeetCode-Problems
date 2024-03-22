class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int i = 0, j = 0, n = word1.size(), m = word2.size();
        string ans = "";
        while(i < n && j < m){
            ans += word1[i++];
            ans += word2[j++];
        }
        if (i < n) copy(word1.begin() + i, word1.end(), back_inserter(ans));
        if (j < m) copy(word2.begin() + j, word2.end(), back_inserter(ans));
        return ans;
    }
};