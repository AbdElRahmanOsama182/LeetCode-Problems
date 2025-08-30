class Solution {
public:
    int isWinner(vector<int>& player1, vector<int>& player2) {
        int n = player1.size(),  sc1 = 0, sc2 = 0, h1 = 0, h2 = 0;
        for (int i = 0; i < n; i++) {
            sc1 += h1 > 0 ? 2 * player1[i] : player1[i];
            sc2 += h2 > 0 ? 2 * player2[i] : player2[i];
            h1--;
            h2--;
            if (player1[i] == 10) h1 = 2;
            if (player2[i] == 10) h2 = 2;
        }
        if (sc1 > sc2) return 1;
        if (sc2 > sc1) return 2;
        return 0;
    }
};