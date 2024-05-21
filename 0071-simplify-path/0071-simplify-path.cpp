class Solution {
public:
    string simplifyPath(string path) {
        string ans = "";
        vector<string> s;
        string cur = "";
        for (char c : path) {
            cout<<cur<<endl;
            if (c == '/') {
                if (cur.empty()) continue;
                if (cur == "..") {
                    if (!s.empty())
                        s.pop_back();
                }
                else if (cur != ".") {
                    s.push_back(cur);
                }
                cur = "";
            }
            else cur += c;
        }
        if (!cur.empty()) {
            if (cur == "..") {
                if (!s.empty())
                    s.pop_back();
            }
            else if (cur != ".") {
                s.push_back(cur);
            }
        }
        for (auto& ss : s) {
            ans += "/";
            ans += ss;
        }
        return ans.empty()? "/" : ans;
    }
};