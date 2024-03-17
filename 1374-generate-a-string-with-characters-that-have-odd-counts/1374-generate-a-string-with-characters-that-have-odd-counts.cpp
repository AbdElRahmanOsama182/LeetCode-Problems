class Solution {
public:
    string generateTheString(int n) {
        string s="";
        for (int i = 0; i < n-1; i++)
            s+='x';
        if (n%2==0)
            s+='y';
        else
            s+='x';
        return s;
    }
};