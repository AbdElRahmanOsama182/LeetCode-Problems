class Solution {
public:
    bool isHappy(int n) {
        int slow = n, fast = n;
        do {
            slow = squareDigSum(slow);
            fast = squareDigSum(squareDigSum(fast));
        } while (slow != fast);
        return slow == 1;
    }

    int squareDigSum(int n) {
        int m = 0;
        while (n > 0) {
            m += (n % 10) * (n % 10);
            n /= 10;
        }
        return m;
    }
};