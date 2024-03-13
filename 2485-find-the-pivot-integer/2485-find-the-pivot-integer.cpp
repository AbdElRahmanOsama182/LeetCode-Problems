class Solution {
public:
    int pivotInteger(int n) {
        double x = sqrt(n*(n+1)/2);
        if (x == int(x)) return x;
        return -1;
    }
};