class Solution {
public:
    void dfs(vector<vector<int>>& rooms, vector<bool>& visited, int i, int& cnt){
        visited[i] = true;
        cnt++;
        for (auto x : rooms[i]){
            if (!visited[x]){
                dfs(rooms, visited, x, cnt);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size(), cnt = 0;
        vector<bool> visited(n, false);
        dfs(rooms, visited, 0, cnt);
        return cnt == n;
    }
};