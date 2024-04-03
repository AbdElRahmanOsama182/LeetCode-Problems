class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = spells.size();
        vector<int> ans;
        sort(potions.begin(), potions.end());
        for(int i=0; i<n; i++){
            long req = (success + spells[i] - 1)/spells[i];
            auto it = lower_bound(potions.begin(), potions.end(), req);
            ans.push_back(potions.end() - it);
        }
        return ans;
    }
};