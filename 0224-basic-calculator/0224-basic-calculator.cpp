class Solution {
public:
    int calculate(string s) {
        stack<pair<int, int>> st;
        int n = s.size();
        int num = 0;
        int res = 0;
        int sign = 1;
        for(int i=0; i<n; i++){
            if(s[i] == ' ') continue;
            if(isdigit(s[i])){
                num = 0;
                while(i<n && isdigit(s[i])){
                    num = num*10 + (s[i]-'0');
                    i++;
                }
                i--;
                res += sign*num;
                sign = 1;
            }
            else if(s[i] == '('){
                st.push({res, sign});
                res = 0;
                sign = 1;
            }
            else if(s[i] == ')'){
                res = st.top().first + (st.top().second*res);
                st.pop();
            }
            else if(s[i] == '-')
                sign = -1*sign;
        }
        return res;
    }
};