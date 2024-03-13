class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for (auto i:tokens) {
            if (i=="+" || i=="-" || i=="*" || i=="/") {
                int x = st.top();
                st.pop();
                int y = st.top();
                st.pop();
                if (i=="+") st.push(x+y);
                else if (i=="-") st.push(y-x);
                else if (i=="*") st.push(x*y);
                else st.push(y/x);
            }
            else {
                st.push(stoi(i));
            }
        }
        return st.top();
    }
};