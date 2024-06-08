class Solution {
public:
    int arraySign(vector<int>& nums) {
        bool neg = false;
        for (int num : nums) 
            if (num == 0) return 0;
            else if (num < 0) neg = !neg;
        return neg ? -1 : 1;    
    }
};