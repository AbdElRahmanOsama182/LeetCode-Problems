class Solution {
public:
    bool isVowel(char c) {
        return c == 'a' || c == 'e'
            || c == 'i' || c == 'o'
            || c == 'u';
    }
    int maxVowels(string s, int k) {
        int cnt = 0, n = s.size();
        for (int i = 0; i < k; i++) 
            cnt += isVowel(s[i]);
        int maxCnt = cnt;
        for (int i = k; i < n; i++) {
            cnt += isVowel(s[i]) - isVowel(s[i - k]);
            maxCnt = max(maxCnt, cnt);
        }
        return maxCnt;
    }
};