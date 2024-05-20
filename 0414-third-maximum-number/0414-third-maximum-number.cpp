class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int> three;
        for (int& num : nums) {
            if (three.count(num)) continue;
            if (three.size() < 3) three.insert(num);
            else {
                if (*three.begin() < num) {
                    three.erase(three.begin());
                    three.insert(num);
                }
            }
        }
        return (three.size() == 3)? *three.begin() : *three.rbegin();
    }
};