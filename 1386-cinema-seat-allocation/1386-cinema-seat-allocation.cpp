class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        int ans = 2*n;
        unordered_map<int, int> mp;
        for(auto& seat: reservedSeats){
            if (seat[1] == 1 || seat[1] == 10) continue;
            mp[seat[0]] |= 1<<(seat[1]-2);
        }
        for(auto& [row, mask]: mp){
            bool left = mask&0b11110000;
            bool right = mask&0b00001111;
            bool middle = mask&0b00111100;
            ans -= (left && right && middle) ? 2 : 1;
        }
        return ans;
    }
};