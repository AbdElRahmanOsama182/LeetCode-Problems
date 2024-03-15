class Solution {
public:
    bool checkRecord(string s) {
        int countA = 0;
        int countL = 0;
        for (char c : s){
            if (c == 'L')
                countL++;
            else 
                countL = 0;
            if (c == 'A')
                countA++;
            if (countA == 2 || countL == 3)
                return false;
        }
        return true; 
    }
};