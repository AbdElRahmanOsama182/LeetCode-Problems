class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        vector<int> ans;
        for (int i = 0; i < expression.size(); i++) {
            if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*') {
                vector<int> left = diffWaysToCompute(expression.substr(0,i));
                vector<int> right = diffWaysToCompute(expression.substr(i+1));
                for (int x:left) {
                    for (int y:right) {
                        if (expression[i] == '+') ans.push_back(x+y);
                        else if (expression[i] == '-') ans.push_back(x-y);
                        else ans.push_back(x*y);
                    }
                }                
            }
        }
        if (ans.size() == 0) ans.push_back(stoi(expression));
        return ans;
    }
};