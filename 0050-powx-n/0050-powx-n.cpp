class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0||x==1) return 1;
        if (n < 0) return 1/x*1/myPow(x, -(n+1));
        double sqrt = myPow(x, n/2);
        if (n%2 == 0) return sqrt*sqrt;
        return x*sqrt*sqrt;
    }
};