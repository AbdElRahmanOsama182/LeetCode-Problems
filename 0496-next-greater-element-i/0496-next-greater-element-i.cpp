class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> mono;
        unordered_map<int, int> mp;
        for (int i = nums2.size() - 1; i >= 0; i--){
            while (!mono.empty() && mono.top() <= nums2[i]) mono.pop();
            if (mono.empty()) mp[nums2[i]] = -1;
            else mp[nums2[i]] = mono.top();
            mono.push(nums2[i]);
        }
        int n = nums1.size();
        vector<int> ans(n);
        for (int i = 0; i < n; i++) ans[i] = mp[nums1[i]];
        return ans;
    }
};