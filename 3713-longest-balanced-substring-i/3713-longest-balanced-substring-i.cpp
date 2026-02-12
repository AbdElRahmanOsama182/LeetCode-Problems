class Solution {
public:
    int longestBalanced(string s) {
        int n = s.size(), ans = 0;
        vector<int> freq(26);
        for (int i = 0; i < n; i++) {
            fill(freq.begin(), freq.end(), 0);
            for (int j = i; j < n; j++) {
                bool bal = true;
                int c = s[j] - 'a';
                ++freq[c];
                for (auto x : freq) {
                    if (x && x != freq[c]) {
                        bal = false;
                        break;
                    }
                }
                if (bal) ans = max(ans, j-i+1);
            }
        }
        return ans;
    }
};