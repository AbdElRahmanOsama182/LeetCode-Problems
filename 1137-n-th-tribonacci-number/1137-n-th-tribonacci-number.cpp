class Solution {
public:  
    int tribonacci(int n) {
        if (n == 0) return 0;
        int prev = 1, prev1 = 1, prev2 = 0, curr = 1;
        for (int i = 3; i <= n; i++) {
            curr = prev+prev1+prev2;
            prev2 = prev1;
            prev1 = prev;
            prev = curr;
        }
        return curr;
    }
};