class Solution {
public:

    int maxLength(vector<string>& arr) {
        if (arr.size() == 0) return 0;
        int n = arr.size();
        int ans = 0;
        vector<bool> vis(26, false);
        comb(arr, 0, vis, ans);
        return ans;
    }

    void comb(vector<string>& arr, int idx, vector<bool>& vis, int& ans){
        if (idx == arr.size()){
            int len = 0;
            for (bool b : vis){
                if (b) len++;
            }
            ans = max(ans, len);
            return;
        }
        comb(arr, idx + 1, vis, ans);   
        if (check(arr[idx], vis)){
            comb(arr, idx + 1, vis, ans);
            for (char c : arr[idx])
                vis[c - 'a'] = false;
        }
    }

    bool check(string& s, vector<bool>& vis){
        vector<bool> temp(26, false);
        for (char c : s){
            if (temp[c - 'a'] || vis[c - 'a']) return false;
            temp[c - 'a'] = true;
        }
        for (int i = 0; i < 26; i++){
            if (temp[i]) vis[i] = true;
        }
        return true;
    }
};