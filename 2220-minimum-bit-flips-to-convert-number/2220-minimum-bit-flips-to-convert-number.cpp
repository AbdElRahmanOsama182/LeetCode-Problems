class Solution {
public:
    int minBitFlips(int start, int goal) {
        int flip = 0, n = 32;
        while (n--) {
            if((start & 1) != (goal & 1))
                flip++;
            start >>= 1;
            goal >>= 1;
        }
        return flip;
    }
};