class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<int> common(26, 0);
        for (char& c : words[0]) common[c - 'a']++;
        for (int i = 1; i < words.size(); i++) {
            vector<int> freq(26, 0);
            for (char& c : words[i]) freq[c - 'a']++;
            for (int j = 0; j < 26; j++) common[j] = min(common[j], freq[j]);
        }
        vector<string> ans;
        for (int i = 0; i < 26; i++) {
            while (common[i]--) ans.push_back(string(1, 'a' + i));
        }
        return ans;
    }
};