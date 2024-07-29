class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n = rating.size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int l1 = 0, l2 = 0, r1 = 0, r2 = 0;
            for (int j = 0; j < i; j++)
                if (rating[j] < rating[i]) l1++;
                else if (rating[j] > rating[i]) l2++;
            for (int j = i+1; j < n; j++)
                if (rating[j] < rating[i]) r1++;
                else if (rating[j] > rating[i]) r2++;
            ans += l1*r2 + l2*r1;
        }
        return ans;     
    }
};