class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        map<string, int> mp1, mp2;
        string temp = "";
        for (auto &c : s1) {
            if (c == ' ') {
                mp1[temp]++;
                temp = "";
            } 
            else 
                temp += c;
        }
        mp1[temp]++;
        temp = "";
        for (auto &c : s2) {
            if (c == ' ') {
                mp2[temp]++;
                temp = "";
            } 
            else 
                temp += c;
        }
        mp2[temp]++;
        vector<string> ans;
        for (auto &[s, cnt] : mp1) 
            if (cnt == 1 && !mp2.count(s)) 
                ans.push_back(s);
        for (auto &[s, cnt] : mp2)
            if (cnt == 1 && !mp1.count(s)) 
                ans.push_back(s);
        return ans;
    }
};