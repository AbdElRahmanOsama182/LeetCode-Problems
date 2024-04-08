class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int n = students.size();
        queue<int> q;
        for(auto i: students) q.push(i);
        int cnt = 0;
        for(auto i: sandwiches){
            if (q.empty()) break;
            cnt = 0;
            while (q.front() != i){
                q.push(q.front());
                q.pop();
                cnt++;
                if (cnt == q.size()) return q.size();
            }
            q.pop();
        }
        return q.size();
    }
};