class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size(), m = t.size();
        if ( n == 0 || n < m) return "";
        int minLen = INT_MAX, start = 0, end = 0, cnt = 0, minStart = 0;
        vector<int> hash(128, 0);
        for (char c : t) hash[c]++;
        for (int i = 0; i < n; i++){
            if (hash[s[i]] > 0) cnt++;
            hash[s[i]]--;
            while (cnt == m){
                if (minLen > i - start + 1){
                    minLen = i - start + 1;
                    minStart = start;
                }
                hash[s[start]]++;
                if (hash[s[start]] > 0) cnt--;
                start++;
            }
        }
        return minLen == INT_MAX ? "" : s.substr(minStart, minLen);
    }
};