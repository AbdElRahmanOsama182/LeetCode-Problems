class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        int mx = max(*max_element(seats.begin(), seats.end())
                    ,*max_element(students.begin(), students.end()));
        vector<int> diffs(mx, 0);
        for (int s : seats) diffs[s - 1]++;
        for (int s : students) diffs[s - 1]--;
        int ans = 0, d = 0;
        for (int diff : diffs) {
            ans += abs(d);
            d += diff;
        }
        return ans;
    }
};