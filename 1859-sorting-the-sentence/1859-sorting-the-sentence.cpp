class Solution {
public:
    string sortSentence(string s) {
        vector<string> words(9);
        string word = "";
        int n = s.size();
        for(char c: s){
            if (c == ' ')
                continue;
            if (c >= '0' && c <= '9'){
                words[c - '1'] = word;
                word = "";
            }
            else
                word += c;
        }
        string res = "";
        for(string word: words){
            if (word == "")
                break;
            res += word + " ";
        }
        res.pop_back();
        return res;
    }
};