class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        sort(words.begin(), words.end(), [](string &a, string &b){
            return a.size() < b.size();
        });
        unordered_set<string> dict;
        vector<string> res;
        for(auto word: words){
            if (isConcat(word, dict)){
                res.push_back(word);
            }
            dict.insert(word);
        }
        return res;
    }

    bool isConcat(string s, unordered_set<string> &dict){
        int n = s.size();
        vector<bool> dp(n+1, false);
        dp[0] = true;
        for(int i=1; i<=n; i++){
            for(int j=0; j<i; j++){
                if (dp[j] && dict.find(s.substr(j, i-j)) != dict.end()){
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n];
    }
};