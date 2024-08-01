class Solution {
public:
    int countSeniors(vector<string>& details) {
        int ans = 0, age;
        for (string &s : details) {
            age = stoi(s.substr(11, 2));
            if (age > 60) ans++;
        }
        return ans;
    }
};