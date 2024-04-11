class Solution {
public:
    string addBinary(string a, string b) {
        int n = a.size(), m = b.size();
        if (n < m) return addBinary(b, a);
        int carry = 0;
        string res = "";
        for (int i = 0; i < m; i++){
            int sum = (a[n-i-1]-'0') + (b[m-i-1]-'0') + carry;
            res.append(to_string(sum%2));
            carry = sum/2;
        }
        for (int i = m; i < n; i++){
            int sum = (a[n-i-1]-'0') + carry;
            res.append(to_string(sum%2));
            carry = sum/2;
        }
        if (carry) res += to_string(carry);
        reverse(res.begin(),res.end());
        return res;
    }
};