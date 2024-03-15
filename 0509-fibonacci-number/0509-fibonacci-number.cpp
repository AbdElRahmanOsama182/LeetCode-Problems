class Solution {
public:
    int fibs[31] = {0};
    int fib(int n) {
        if (fibs[n] != 0) return fibs[n];
        if (n < 2) return fibs[n] = n;
        return fibs[n] = fib(n-1) + fib(n-2);
    }


};