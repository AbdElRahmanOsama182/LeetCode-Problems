class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> in(n+1, 0), out(n+1, 0);
        for(auto i: trust){
            out[i[0]]++;
            in[i[1]]++;
        }
        int judge = -1;
        for(int i=1; i<=n; i++){
            if(in[i] == n-1 && out[i] == 0) {
                if(judge == -1) 
                    judge = i;
                else 
                    return -1;
                
            }
        }
        return judge;
    }
};