class Solution {
public:
    int minFlips(int a, int b, int c) {
        int cnt = 0, x, y, z;
        for(int i=0; i<32; i++){
            x = a&1;
            y = b&1;
            z = c&1;
            if(z == 1){
                if(x == 0 && y == 0) cnt++;
            }
            else{
                cnt += x + y;
            }
            a >>= 1;
            b >>= 1;
            c >>= 1;
        }
        return cnt;
    }
};