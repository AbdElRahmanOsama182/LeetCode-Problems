class Solution {
public:
    int climbStairs(int n) {
        int prev = 1, curr = 1, temp;
        for (int i = 2; i <= n; i++) {
            temp = curr;
            curr = prev + curr;
            prev = temp;
        }
        return curr;
    }
};