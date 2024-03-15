#define fori(i,x,n) for(int i=x; i<n; i++)

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> indegree(numCourses, 0);
        for (auto i:prerequisites){
            graph[i[1]].push_back(i[0]);
            indegree[i[0]]++;
        }
        queue<int> q;
        fori(i,0,numCourses){
            if (indegree[i] == 0) q.push(i);
        }
        vector<int> ans;
        while (!q.empty()){
            int u = q.front();
            ans.push_back(u);
            q.pop();
            for (auto i:graph[u]){
                indegree[i]--;
                if (indegree[i] == 0) q.push(i);
            }
        }
        if (ans.size() == numCourses) return ans;
        return {};
    }
};