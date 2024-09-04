class Solution {
public:
    vector<int> dir = {0, 1, 0, -1, 0};
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        unordered_set<int> obs;
        for (auto &o : obstacles) 
            obs.insert(hash(o[0], o[1]));
        int x = 0, y = 0, direction = 0, maxDist = 0;
        for (auto &c : commands) {
            if (c == -2) 
                direction = (direction + 3) % 4;
            else if (c == -1) 
                direction = (direction + 1) % 4;
            else {
                for (int i = 0; i < c; i++) {
                    int nx = x + dir[direction], ny = y + dir[direction+1];
                    if (obs.count(hash(nx, ny)))
                        break;
                    x = nx, y = ny;
                    maxDist = max(maxDist, x*x + y*y);
                }
            }
        }
        return maxDist;
    }
    int hash(int x, int y) {
        return x + (6e4+1) * y;
    }
};