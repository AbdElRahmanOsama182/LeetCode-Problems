class Solution {
public:

    string lower(string s) {
        for (char& c : s) c = tolower(c);
        return s;
    }

    string vows(string s) {
        for (char& c : s) {
            if (c =='a' || c == 'o' || c == 'e' || c == 'i' || c == 'u')
                c = '-';
        }
        return s;
    }
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        unordered_map<string, int> exact;
        unordered_map<string, string> caps, vow;
        for (auto& w : wordlist) {
            exact[w]++;
            string l = lower(w);
            string v = vows(l);
            if (!caps.contains(l)) caps[l] = w;
            if (!vow.contains(v)) vow[v] = w;
        }
        
        vector<string> ans;
        for(auto& w : queries) {
            if (exact.contains(w)) {
                ans.push_back(w);
                continue;
            }
            string l = lower(w);
            if (caps.contains(l)) {
                ans.push_back(caps[l]);
                continue;
            } 
            string v = vows(l);
            if (vow.contains(v)) {
                ans.push_back(vow[v]);
                continue;
            }
            ans.push_back("");
        }
        return ans;
    }
};