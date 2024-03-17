class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string s = "123456789";
        vector<int> ans;
        for (int i = 0; i < s.size(); i++) {
            for (int j = i; j < s.size(); j++) {
                int x = stoi(s.substr(i,j-i+1));
                if (x>=low && x<=high) ans.push_back(x);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};