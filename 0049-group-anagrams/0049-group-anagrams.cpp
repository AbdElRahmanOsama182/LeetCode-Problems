class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for(auto& s: strs){
            string hash = "";
            vector<int> freq(26, 0);
            for(auto& c: s) 
                freq[c-'a']++;
            for(int i=0; i<26; i++)
                hash.append(to_string(freq[i]) + "#");
            mp[hash].push_back(s);
        }
        vector<vector<string>> res;
        for(auto& p: mp)
            res.push_back(p.second);
        return res;
    }
};