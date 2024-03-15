class Solution {
public:

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size(), cnt = 0;
        vector<bool> vis(n, false);
        queue<int> q;
        q.push(0);
        vis[0] = true;
        cnt++;
        while(!q.empty()){
            int u = q.front();
            q.pop();
            for(auto v: rooms[u]){
                if(!vis[v]){
                    vis[v] = true;
                    q.push(v);
                    cnt++;
                }
            }
        }
        return cnt == n;
    }
};