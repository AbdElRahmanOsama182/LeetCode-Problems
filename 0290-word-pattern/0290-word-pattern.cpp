class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> mp;
        unordered_map<string, char> mp2;
        vector<string> words;
        string word = "";
        for(char c: s){
            if (c == ' '){
                words.push_back(word);
                word = "";
            }
            else{
                word += c;
            }
        }
        words.push_back(word);
        if (pattern.size() != words.size()) return false;
        for(int i=0; i<pattern.size(); i++){
            if (mp.find(pattern[i]) == mp.end() && mp2.find(words[i]) == mp2.end()){
                mp[pattern[i]] = words[i];
                mp2[words[i]] = pattern[i];
            }
            else if (mp.find(pattern[i]) == mp.end() || mp2.find(words[i]) == mp2.end()){
                return false;
            }
            else if (mp[pattern[i]] != words[i] || mp2[words[i]] != pattern[i]){
                return false;
            }
        }
        return true;
    }
};