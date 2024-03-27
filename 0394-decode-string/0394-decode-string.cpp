class Solution {
public:
    string decodeString(string s) {
        stack<int> repeat;
        stack<string> str;
        string res = "", temp = "";
        int num = 0;
        for (char c : s){
            if (isdigit(c)){
                num = num*10 + c - '0';
            }
            else if (c == '[') {
                repeat.push(num);
                str.push(temp);
                num = 0;
                temp = "";            
            }
            else if (c == ']'){
                int n = repeat.top();
                repeat.pop();
                string t = str.top();
                str.pop();
                for (int i = 0; i < n; i++) 
                    t += temp;
                temp = t;
            }
            else temp += c;
        }
        return temp;
    }
};