class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> s;
        s.push(asteroids[0]);
        for (int i = 1; i < asteroids.size(); i++){
            if (s.empty() || s.top() * asteroids[i] > 0)
                s.push(asteroids[i]);
            else if (s.top() < 0 && asteroids[i] > 0) 
                s.push(asteroids[i]);
            else{
                while (!s.empty() && s.top() > 0 && asteroids[i] < 0) {
                    int top = s.top();
                    s.pop();
                    if (abs(top) == abs(asteroids[i]))
                        asteroids[i] = 0;
                    else if (abs(top) > abs(asteroids[i]))
                        asteroids[i] = top;
                }
                if (asteroids[i] != 0)
                    s.push(asteroids[i]);
            }
        }
        vector<int> res;
        while (!s.empty()){
            res.push_back(s.top());
            s.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};