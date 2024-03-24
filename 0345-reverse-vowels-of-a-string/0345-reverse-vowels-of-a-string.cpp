class Solution {
public:
    bool isVowel(char c){
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

    string reverseVowels(string s) {
        int n = s.size();
        int i = 0, j = n-1;
        while (i < j){
            while (i < j && !isVowel(tolower(s[i]))) i++;
            while (i < j && !isVowel(tolower(s[j]))) j--;
            swap(s[i], s[j]);
            i++;
            j--;
        }
        return s;
    }
};