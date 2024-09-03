class Solution {
public:
    int getLucky(string s, int k) {
        int num = 0;
        for (char c : s) {
            int x = c - 'a' + 1;
            while (x) {
                num += x % 10;
                x /= 10;
            }
        }
        --k;
        while (k--) {
            int x = 0;
            while (num) {
                x += num % 10;
                num /= 10;
            }
            num = x;
        }
        return num;
    }
};