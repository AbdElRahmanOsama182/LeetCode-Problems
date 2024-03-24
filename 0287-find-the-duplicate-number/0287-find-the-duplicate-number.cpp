class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        vector<bool> visited(n, false);
        for (int i = 0; i < n; i++){
            if (visited[nums[i]]){
                return nums[i];
            }
            visited[nums[i]] = true;
        }
        return -1;
    }
};