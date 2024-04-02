class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n = s.size();
        if (n != t.size()) return false;
        unordered_map<char, char> mp;
        unordered_map<char, char> mp2;
        for (int i = 0; i < n; i++){
            if (mp.find(s[i]) == mp.end()){
                mp[s[i]] = t[i];
            }
            else{
                if (mp[s[i]] != t[i]) return false;
            }
            if (mp2.find(t[i]) == mp2.end()){
                mp2[t[i]] = s[i];
            }
            else{
                if (mp2[t[i]] != s[i]) return false;
            }
        }
        return true;
    }
};