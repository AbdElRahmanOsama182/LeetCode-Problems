class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<vector<pair<int,bool>>> graph(n);
        for(auto edge:redEdges)
            graph[edge[0]].push_back({edge[1], 0});
        for(auto edge:blueEdges)
            graph[edge[0]].push_back({edge[1], 1});
        vector<vector<int>> dist(n, vector<int>(2, -1));
        queue<pair<int, bool>> q;
        q.push({0, 0});
        q.push({0, 1});
        dist[0][0]=dist[0][1]=0;
        while(!q.empty()){
            auto [u, color]=q.front();
            q.pop();
            for(auto [v, nextColor]:graph[u]){
                if(nextColor!=color && dist[v][nextColor]==-1){
                    dist[v][nextColor]=dist[u][color]+1;
                    q.push({v, nextColor});
                }
            }
        }
        vector<int> ans(n);
        for(int i=0; i<n; i++){
            if(dist[i][0]==-1 && dist[i][1]==-1)
                ans[i]=-1;
            else if(dist[i][0]==-1)
                ans[i]=dist[i][1];
            else if(dist[i][1]==-1)
                ans[i]=dist[i][0];
            else
                ans[i]=min(dist[i][0], dist[i][1]);
        }
        return ans;        
    }
};