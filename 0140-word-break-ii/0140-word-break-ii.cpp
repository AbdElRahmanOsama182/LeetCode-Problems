class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> res;
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        solve(s, dict, 0, "", res);
        return res;
    }

    void solve(string s, unordered_set<string>& dict, int st, string sentence, vector<string>& res){
        if (st == s.size()){
            res.push_back(sentence);
            return;
        }
        for (int i = st; i < s.size(); i++){
            string word = s.substr(st, i-st+1);
            if (dict.find(word) != dict.end()){
                string newSentence = sentence;
                if (sentence.size() > 0) newSentence += " ";
                newSentence += word;
                solve(s, dict, i+1, newSentence, res);
            }
        }
    }
};