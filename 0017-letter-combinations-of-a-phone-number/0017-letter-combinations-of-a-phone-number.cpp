class Solution {
public:
    vector<string> phone = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    void comb(string &digits, int index, string current, vector<string> &combinations){
        if (index == digits.size()){
            combinations.push_back(current);
            return;
        }
        string letters = phone[digits[index] - '2'];
        for (char c : letters){
            comb(digits, index + 1, current + c, combinations);
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> combinations;
        if (digits.empty()) return combinations;
        comb(digits, 0, "", combinations);
        return combinations;
    }
};