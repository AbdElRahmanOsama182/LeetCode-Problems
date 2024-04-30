class Solution {
public:  
    int tribonacci(int n) {
        if (n == 0) return 0;
        int prev0 = 0, prev1 = 1, prev2 = 1;
        for (int i = 3; i <= n; i++) {
            int temp = prev2;
            prev2 += prev1 + prev0;
            prev0 = prev1;
            prev1= temp;
        }
        return prev2;
    }
};