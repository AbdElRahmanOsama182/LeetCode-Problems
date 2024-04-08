class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for(auto s: strs){
            string hash = getHash(s);
            mp[hash].push_back(s);
        }
        vector<vector<string>> res;
        for(auto p: mp)
            res.push_back(p.second);
        return res;
    }
private:
    string getHash(string& s){
        vector<int> freq(26, 0);
        for(auto c: s) 
            freq[c-'a']++;
        string hash = "";
        for(int i=0; i<26; i++)
            hash.append(to_string(freq[i]) + "#");
        return hash;
    }
};