class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> occ(26, 0);
        for (int i = 0; i < s.size(); i++) 
            occ[s[i]-'a'] = i;
        vector<bool> vis(26, false);
        stack<char> st;
        st.push(s[0]);
        vis[s[0]-'a'] = true;
        for (int i = 1; i < s.size(); i++) {
            if (vis[s[i]-'a']) continue;
            while (st.size() && st.top() > s[i] && occ[st.top()-'a'] >= i) {
                vis[st.top()-'a'] = false;
                st.pop();
            }
            st.push(s[i]);
            vis[s[i]-'a'] = true;
        }
        string ans = "";
        while(st.size()) {
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};