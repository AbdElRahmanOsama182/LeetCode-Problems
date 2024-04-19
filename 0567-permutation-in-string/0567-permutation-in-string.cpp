class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;
        vector<int> s1map(26, 0), s2map(26, 0);
        for (int i = 0; i < s1.size(); i++){
            s1map[s1[i] - 'a']++;
            s2map[s2[i] - 'a']++;
        }
        if (s1map == s2map) return true;
        for (int i = s1.size(); i < s2.size(); i++){
            s2map[s2[i] - 'a']++;
            s2map[s2[i - s1.size()] - 'a']--;
            if (s1map == s2map) return true;
        }
        return false;
    }
};