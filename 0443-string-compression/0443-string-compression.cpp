class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size(), cnt = 1;
        string ans = "";
        ans += chars[0];
        for(int i = 1; i < n; i++){
            if (chars[i] == chars[i-1]){
                cnt++;
            }
            else{
                if (cnt > 1){
                    ans += to_string(cnt);
                }
                ans += chars[i];
                cnt = 1;
            }
        }
        if (cnt > 1){
            ans += to_string(cnt);
        }
        for(int i = 0; i < ans.size(); i++){
            chars[i] = ans[i];
        }
        return ans.size();
    }
};