class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        int n = arr.size();
        unordered_map<string, int> mp;
        for (auto i : arr) mp[i]++;
        for (auto i : arr) 
            if (mp[i] == 1) 
                if (--k == 0) return i;
        return "";
    }
};