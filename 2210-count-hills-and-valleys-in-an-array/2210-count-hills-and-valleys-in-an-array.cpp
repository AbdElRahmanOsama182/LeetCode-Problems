class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int st = 0, idx = 1, n = nums.size(), ans = 0;
        while (idx < n ) {
            if (nums[idx] == st) idx++;
            else if (nums[idx] == nums[idx - 1]) idx++;
            else if (nums[idx - 1] > nums[st] && nums[idx - 1] > nums[idx]) {
                cout<<nums[idx-1]<<endl;
                ans++;
                st = idx - 1;
                idx++;
            }
            else if (nums[idx - 1] < nums[st] && nums[idx - 1] < nums[idx]) {
                cout<<nums[idx-1]<<endl;
                ans++;
                st = idx - 1;
                idx++;
            }
            else {
                st = idx - 1;
                idx++;
            }
        }
        return ans;
    }
};