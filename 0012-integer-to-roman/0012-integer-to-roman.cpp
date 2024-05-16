class Solution {
public:
    string intToRoman(int num) {
        vector<char> tens = {'I', 'X', 'C', 'M'};
        vector<char> fives = {'V', 'L', 'D'};
        string res = "";
        int pow = 0;
        while (num){
            int digit = num%10;
            if (digit < 4)
                while (digit--)
                    res += tens[pow];
            else if (digit == 4) {
                res += fives[pow];
                res += tens[pow];
            }
            else if (digit == 9) {
                res += tens[pow+1];
                res += tens[pow];
            }
            else{
                digit -= 5;
                while (digit--)
                    res += tens[pow];
                res += fives[pow];
            }
            num /= 10;
            pow++;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};