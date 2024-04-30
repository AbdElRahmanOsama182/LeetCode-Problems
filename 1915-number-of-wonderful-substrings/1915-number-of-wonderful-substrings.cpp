class Solution {
public:
    long long wonderfulSubstrings(string word) {
        vector<int> freq(1025, 0);
        long long ans = 0;
        freq[0] = 1;
        int mask = 0;
        for (char& c : word) {
            mask ^= (1 << (c - 'a'));;
            ans += freq[mask]++;
            for (int i = 0; i < 10; i++) {
                ans += freq[mask ^ (1 << i)];
            }
        }
        return ans;
    }
};