class Solution {
public:
    bool isVowel(char c){
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

    string reverseVowels(string s) {
        string vowels = "", ans = "";
        for (char c : s){
            if (isVowel(tolower(c)))
                vowels += c;
        }
        int end = vowels.size()-1;
        for (char c : s){
            if (isVowel(tolower(c))){
                ans += vowels[end];
                end--;
            }
            else
                ans += c;
        }
        return ans;
    }
};