class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> p;
        sort(nums.begin(),nums.end());
        do{
            p.push_back(nums);
        } while (next_permutation(nums.begin(),nums.end()));
        return p;
    }
};