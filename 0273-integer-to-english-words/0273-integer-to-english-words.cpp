class Solution {
public:
    string numberToWords(int num) {
        if (num == 0) return "Zero";
        string res = "";
        while (num > 0) {
            if (num >= 1e9) {
                res += toWords(num/1e9) + " Billion ";
                num %= (int)1e9;
            } else if (num >= 1e6) {
                res += toWords(num/1e6) + " Million ";
                num %= (int)1e6;
            } else if (num >= 1e3) {
                res += toWords(num/1e3) + " Thousand ";
                num %= (int)1e3;
            } else {
                res += toWords(num);
                num = 0;
            }
        }    
        if (res.back() == ' ')
        res.pop_back();
        return res;   
    }

    string toWords(int num) {
        vector<string> v1 = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
        vector<string> v2 = {"", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
        vector<string> v3 = {"", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
        string res = "";
        if (num >= 100) {
            res += v1[num/100] + " Hundred ";
            num %= 100;
        }
        if (num >= 20) {
            res += v2[num/10] + " ";
            num %= 10;
        } else if (num == 10) {
            res += v2[1] + " ";
            num %= 10;
        } else if (num > 10) {
            res += v3[num-10] + " ";
            num = 0;
        }
        if (num > 0) {
            res += v1[num] + " ";
        }
        if (res.back() == ' ') res.pop_back();
        return res;
    }
};