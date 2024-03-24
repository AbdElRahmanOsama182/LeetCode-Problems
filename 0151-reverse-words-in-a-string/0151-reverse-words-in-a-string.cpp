class Solution {
public:
    string reverseWords(string s) {
        vector<string> words;
        string word = "";
        for (int i = 0; i < s.size(); i++){
            if (s[i] == ' '){
                if (word != ""){
                    words.push_back(word);
                    word = "";
                }
            }
            else{
                word += s[i];
            }
        }
        if (word != ""){
            words.push_back(word);
        }
        string ans = "";
        for (int i = words.size()-1; i > 0; i--){
            ans += words[i];
            ans += " ";
        }
        ans += words[0];
        return ans;
    }
};