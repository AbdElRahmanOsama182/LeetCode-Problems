class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(),arr.end(), [&](int a, int b){
            int cntA = __builtin_popcount(a);
            int cntB = __builtin_popcount(b);
            if (cntA == cntB) return a < b;
            return cntA < cntB;
        });
        return arr;
    }
};