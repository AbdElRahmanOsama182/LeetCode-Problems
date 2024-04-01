class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> monoStack;
        int n = nums.size();
        vector<int> res(n, -1);
        for (int i = 0; i < 2*n; i++){
            while (!monoStack.empty() && nums[monoStack.top()] < nums[i%n]){
                res[monoStack.top()] = nums[i%n];
                monoStack.pop();
            }
            if (i < n) monoStack.push(i);
        }
        return res;
    }
};