class Solution {
public:
    int sumOfTheDigitsOfHarshadNumber(int x) {
        int sum = digitsSum(x);
        if (x%sum == 0) return sum;
        return -1;
    }
    int digitsSum(int x){
        int sum = 0;
        while (x > 0){
            sum += x % 10;
            x /= 10;
        }
        return sum;
    }
};