class Solution {
public:
    int hammingWeight(int n) {
        int cnt = 0;
        while (n){
            cnt++;
            n = n & (n-1);
        }
        return cnt;
    }
};