class Solution {
public:
    int solve(string& s, int k, int st, int ed) {
        int ans = 0;
        if (st == s.size()) return 0;
        if (ed == s.size()) {
            ans = solve(s,k,st+1,st+2);
        }
        else {
        int diff = abs(s[st]-s[ed]);
        cout<<"diff "<< s[st] << " " << s[ed] << " "<<diff<<endl;
        if (diff <= k){
            ans = max(solve(s,k,ed,ed+1)+1,solve(s,k,st+1,st+2));
        }
        else
            ans = max(solve(s,k,st,ed+1),solve(s,k,st+1,st+2));
        }
    
        cout <<st<<" "<<ed <<" => "<<ans <<endl;
        return ans;
    }
    int longestIdealString(string s, int k) {
        int n = s.size();
        if (n == 1) return 1;
        vector<int> dp(n+1,0);
        return solve(s,k,0, 1)+1;
    }
};