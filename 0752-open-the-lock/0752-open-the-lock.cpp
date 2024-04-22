class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        vector<bool> dead(1e4,false);
        for (string s:deadends)
            dead[stoi(s)] = true;
        if (dead[0]) return -1;
        dead[0] = true;
        queue<string> q;
        q.push("0000");
        int turns = 0;
        while (!q.empty())
        {
            int n = q.size();
            for (int i = 0; i < n; i++)
            {
                string front = q.front(), temp;
                int x;
                q.pop();
                // cout<<front<<endl;
                if (front == target) return turns;
                for (int j = 0; j < 4; j++)
                {
                    temp = front;
                    temp[j] = (temp[j] - '0' + 1) % 10 + '0';
                    // cout<<temp<<" ";
                    x = stoi(temp);
                    if (!dead[x]) {
                        q.push(temp);
                        dead[x] = true;
                    }
                    temp = front;
                    temp[j] = (temp[j] - '0' + 9) % 10 + '0';
                    x = stoi(temp);
                    // cout<<temp<<" ";
                    if (!dead[x]) {
                        q.push(temp);
                        dead[x] = true;
                    }
                }
                // cout<<endl;
            }
            turns++;
        }
        return -1;
    }
};