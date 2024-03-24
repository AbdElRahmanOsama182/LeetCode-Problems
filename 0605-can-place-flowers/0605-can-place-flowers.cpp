#define fastIO        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

class Solution {
public:
    int maxFlowers(int x) {
        if (x < 1) return 0;
        return (x+1)/2;
    }
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        fastIO
        int cnt = 0, m = flowerbed.size(), mx = 0;
        for (int i = 0; i < m; i++){
            if (flowerbed[i] == 1) {
                mx += maxFlowers(cnt-1);
                cnt = -1;
            }
            else cnt++;
        }
        mx += maxFlowers(cnt);
        return mx >= n;
    }
};