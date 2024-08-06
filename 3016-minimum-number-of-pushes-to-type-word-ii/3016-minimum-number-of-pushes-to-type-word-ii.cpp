class Solution {
public:
    int minimumPushes(string word) {
        vector<int> v(26,0);
        for(auto i:word) v[i-'a']++;
        sort(v.rbegin(),v.rend());
        int ans=0, numB = 0;
        for(auto i:v){
            if(i==0) break;
            ans+= i*(numB/8+1);
            numB++;
        }
        return ans;
    }
};