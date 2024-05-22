class Solution {
public:
    vector<vector<bool>> isPalindrome;
    vector<vector<string>> partition(string s) {
        int n = s.size();
        isPalindrome = vector<vector<bool>>(n, vector<bool>(n, false));
        buildPalindrome(s);
        vector<vector<string>> parts;
        vector<string> part;
        backtrack(s, 0, part, parts);
        return parts;
    }

    void buildPalindrome(string& s) {
        int n = s.size();
        for (int i = 0; i < n; i++)
            isPalindrome[i][i] = true;
        for (int i = 0; i < n - 1; i++)
            isPalindrome[i][i + 1] = s[i] == s[i + 1];
        for (int len = 3; len <= n; len++) {
            for (int i = 0; i + len - 1 < n; i++) {
                int j = i + len - 1;
                isPalindrome[i][j] = isPalindrome[i + 1][j - 1] && s[i] == s[j];
            }
        }
    }

    void backtrack(string& s, int start, vector<string>& part, vector<vector<string>>& parts) {
        if (start == s.size()) {
            parts.push_back(part);
            return;
        }
        string str = "";
        for (int i = start; i < s.size(); i++) {
            str += s[i];
            if (isPalindrome[start][i]) {
                part.push_back(str);
                backtrack(s, i + 1, part, parts);
                part.pop_back();
            }
        }
    }                
};