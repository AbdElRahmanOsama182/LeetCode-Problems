class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size(), group = 0;
        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end());
        vector<list<int>> groups;
        unordered_map<int, int> numGroup;
        numGroup[sorted[0]] = 0;
        groups.push_back({sorted[0]});
        for (int i = 1; i < n; i++) {
            if (sorted[i] - sorted[i - 1] > limit) {
                group++;
                groups.push_back({sorted[i]});
            } else {
                groups[group].push_back(sorted[i]);
            }
            numGroup[sorted[i]] = group;
        }
        for (int i = 0; i < n; i++) {
            int cur = numGroup[nums[i]];
            nums[i] = groups[cur].front();
            groups[cur].pop_front();
        }
        return nums;
    }
};