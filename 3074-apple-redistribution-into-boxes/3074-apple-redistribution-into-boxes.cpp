class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int apples = 0;
        for (int& a : apple) apples += a;
        sort(capacity.rbegin(), capacity.rend());
        int cap = 0;
        for (int i = 0; i < capacity.size(); i++) {
            cap += capacity[i];
            if (cap >= apples) return i + 1;
        }
        return capacity.size();
    }
};