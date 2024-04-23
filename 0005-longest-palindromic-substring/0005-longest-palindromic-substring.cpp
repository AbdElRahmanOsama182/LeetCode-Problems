class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size(), l, r , maxL = -1;
        string ans ="";
        for (int i = 0; i < n; i++) {
            l = i, r = i;
            while (l > -1 && r < n && s[l] == s[r]) {
                l--;
                r++;
            }
            l++,r--;
            if (r-l+1 > maxL) {
                maxL = r-l+1;
                ans = s.substr(l,maxL);
            }
            l = i, r = i+1;
            while (l > -1 && r < n && s[l] == s[r]) {
                l--;
                r++;
            }
            l++,r--;
            if (r-l+1 > maxL) {
                maxL = r-l+1;
                ans = s.substr(l,maxL);
            }
        }
        return ans;
    }
};