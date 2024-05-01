class Solution {
public:
    string reversePrefix(string word, char ch) {
        int idx = word.find_first_of(ch);
        if (!idx) return word;
        reverse(word.begin(), word.begin() + idx + 1);
        return word;
    }
};