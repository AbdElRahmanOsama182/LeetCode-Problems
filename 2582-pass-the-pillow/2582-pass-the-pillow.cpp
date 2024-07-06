class Solution {
public:
    int passThePillow(int n, int time) {
        int x = time%(2*(n-1));
        if (x < n) return x + 1;
        x -= n - 1;
        return n - x;
    }
};