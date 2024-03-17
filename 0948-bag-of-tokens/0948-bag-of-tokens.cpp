class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());
        int n = tokens.size(), ans = 0, score = 0, i = 0, j = n-1;
        while (i <= j){
            if (power >= tokens[i]){
                power -= tokens[i];
                i++;
                score++;
                ans = max(ans, score);
            }
            else if (score > 0){
                power += tokens[j];
                j--;
                score--;
            }
            else break;
        }
        return ans;
    }
};