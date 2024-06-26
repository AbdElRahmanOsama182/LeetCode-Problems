class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int> freq(26, 0);
        for (char c : s) freq[c - 'a']++;
        for (char c : t) 
            if (freq[c - 'a']-- == 0) 
                return c;
        return ' ';
    }
};