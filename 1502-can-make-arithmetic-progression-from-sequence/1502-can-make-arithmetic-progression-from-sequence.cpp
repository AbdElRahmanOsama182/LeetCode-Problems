class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        unordered_set<int> set(arr.begin(), arr.end());
        int mn = *min_element(arr.begin(), arr.end());
        int mx = *max_element(arr.begin(), arr.end());
        int n = arr.size();
        int diff = (mx - mn) / (n - 1);
        if (mx - mn == 0) return true;
        if (mx - mn < n - 1) return false;
        for (int num = mn; num <= mx; num += diff) 
            if (!set.count(num)) 
                return false;
        return true;
    }
};