#define fastIO        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        fastIO
        int n = candies.size();
        int maxCandies = *max_element(candies.begin(), candies.end());
        vector<bool> ans(n, false);
        for (int i = 0; i < n; i++){
            if (candies[i] + extraCandies >= maxCandies){
                ans[i] = true;
            }
        }
        return ans;
    }
};