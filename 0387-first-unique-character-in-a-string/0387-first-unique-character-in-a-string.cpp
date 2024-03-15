#define fori(i,x,n) for(int i=x; i<n; i++)
class Solution {
public:
    int firstUniqChar(string s) {
        int n = s.size();
        vector<int> cnt(26,0);
        fori(i,0,n) cnt[s[i]-'a']++;
        fori(i,0,n) if (cnt[s[i]-'a'] == 1) return i;
        return -1;
    }
};