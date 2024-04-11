class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size(), ans = 1, series = 1;
        for (int i = 1; i < n; i++){
                cout<<ans<<" ";
            if (ratings[i-1] > ratings[i]){
                series++;
                ans += series;
            }
            else if (ratings[i-1] == ratings[i]){
                ans += 1;
                series = 1;
            }
            else{
                ans += 2;
                if (i+1<n&&ratings[i+1]<ratings[i]) ans--;
                series = 1;
            }
        }
        cout<<ans;
        return ans;
    }
};