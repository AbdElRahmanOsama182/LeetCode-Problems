class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if(n%groupSize != 0) return false;
        unordered_map<int,int> mp;
        for(auto i:hand) mp[i]++;
        for (auto card : hand) {
            int st = card;
            while (mp[st - 1]) st--;
            while (st <= card) {
                while (mp[st]) {
                    for (int i = 0; i < groupSize; i++) 
                        if (!mp[st + i]--) return false;
                }
                st++;
            }
        }
        return true;
    }
};