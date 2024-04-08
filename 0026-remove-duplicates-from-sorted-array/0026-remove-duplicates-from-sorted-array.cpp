class Solution {
public:
    int removeDuplicates(vector<int>& v) {
        v.resize(distance(v.begin(),unique(v.begin(), v.end())));
        return v.size();
    }
};