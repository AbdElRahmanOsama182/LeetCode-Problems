class Solution {
public:
    string fractionAddition(string expression) {
        int numerator = 0, denominator = 1;
        int sign = 1, tempN, tempD, i = 0, n = expression.size();
        while (i < n) {
            if (expression[i] == '-') {
                sign = -1;
                i++;
            } else if (expression[i] == '+') {
                sign = 1;
                i++;
            }
            tempN = 0;
            while (i < n && expression[i] != '/') 
                tempN = tempN * 10 + (expression[i++] - '0');
            tempN *= sign;
            tempD = 0;
            i++;
            while (i < n && isdigit(expression[i])) 
                tempD = tempD * 10 + (expression[i++] - '0');
            numerator = numerator * tempD + tempN * denominator;
            denominator *= tempD;
            int gcd = __gcd(abs(numerator), abs(denominator));
            numerator /= gcd, denominator /= gcd;
        }
        return to_string(numerator) + "/" + to_string(denominator);
    }
};