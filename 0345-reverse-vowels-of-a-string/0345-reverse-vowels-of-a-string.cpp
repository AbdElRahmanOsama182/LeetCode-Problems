#define fastIO        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

class Solution {
public:
    bool isVowel(char c){
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'
            || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
    }

    string reverseVowels(string s) {
        fastIO
        int n = s.size();
        int i = 0, j = n-1;
        while (i < j){
            while (i < j && !isVowel(s[i])) i++;
            while (i < j && !isVowel(s[j])) j--;
            swap(s[i], s[j]);
            i++;
            j--;
        }
        return s;
    }
};