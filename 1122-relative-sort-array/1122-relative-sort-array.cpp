class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        int mx = *max_element(arr1.begin(), arr1.end());
        vector<int> cnt(mx + 1);
        for (int x : arr1) cnt[x]++;
        vector<int> ans;
        for (int x : arr2) 
            while (cnt[x]-- > 0) 
                ans.push_back(x);
        for (int i = 0; i <= mx; i++)
            while (cnt[i]-- > 0) 
                ans.push_back(i);
        return ans;
    }
};