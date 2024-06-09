class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
        vector<vector<int>> board(3, vector<int>(3, 0));
        for (int i = 0; i < moves.size(); i++) 
            board[moves[i][0]][moves[i][1]] = i % 2 == 0 ? 1 : -1;
        int sumR, sumC;
        for (int i = 0; i < 3; i++) {
            sumR = sumC = 0;
            for (int j = 0; j < 3; j++) {
                sumR += board[i][j];
                sumC += board[j][i];
            }
            if (sumR == 3 || sumC == 3) return "A";
            if (sumR == -3 || sumC == -3) return "B";
        }
        int sumD1 = board[0][0] + board[1][1] + board[2][2];
        int sumD2 = board[0][2] + board[1][1] + board[2][0];
        if (sumD1 == 3 || sumD2 == 3) return "A";
        if (sumD1 == -3 || sumD2 == -3) return "B";
        return moves.size() == 9 ? "Draw" : "Pending";
    }
};