class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);
        for (char c : tasks) freq[c - 'A']++;
        sort(freq.rbegin(), freq.rend());
        int maxFreq = freq[0] - 1;
        int idleSlots = maxFreq * n;
        for (int i = 1; i < 26; i++) idleSlots -= min(maxFreq, freq[i]);
        return tasks.size() + max(0, idleSlots);
    }
};