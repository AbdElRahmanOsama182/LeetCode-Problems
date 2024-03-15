class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        if (k >= n) return "0";
        stack<char> mst;
        for (int i = 0; i < n; i++){
            while (k > 0 && !mst.empty() && mst.top() > num[i]){
                mst.pop();
                k--;
            }
            mst.push(num[i]);
            if (mst.size() == 1 && mst.top() == '0') mst.pop();
        }
        while (k > 0 && !mst.empty()){
            mst.pop();
            k--;
        }
        string ans = "";
        while (!mst.empty()){
            ans += mst.top();
            mst.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans.size() == 0 ? "0" : ans;
    }
};