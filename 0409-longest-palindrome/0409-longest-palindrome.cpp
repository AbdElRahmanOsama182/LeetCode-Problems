class Solution {
public:
    int longestPalindrome(string s) {
        int odd = 0;
        unordered_map<char, int> mp;
        for (char c : s) 
            if (++mp[c]%2 == 1) odd++;
            else odd--;
            if (odd) return s.size() - odd + 1;
            return s.size();
    }
};