class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> freq;
        for (int i : arr) freq[i]++;
        unordered_set<int> s;
        for (auto i : freq){
            if (s.find(i.second) != s.end()) return false;
            s.insert(i.second);
        }
        return true;
    }
};