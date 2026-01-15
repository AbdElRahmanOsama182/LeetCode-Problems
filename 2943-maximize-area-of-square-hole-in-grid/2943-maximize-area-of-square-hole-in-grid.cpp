class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        int h = getMax(hBars), v = getMax(vBars);
        cout << h << " " << v;
        return pow(min(h, v),2);
    }

    int getMax(vector<int>& bars) {
        sort(bars.begin(), bars.end());
        int n = bars.size(), lst, mx = 1;
        int i = 0;
        while(i < n) {
            lst = bars[i]-1;
            while (i+1<n && bars[i+1]==bars[i]+1) i++;
            mx = max(mx, bars[i]+1-lst);
            i++;
        }
        return mx;
    }
};