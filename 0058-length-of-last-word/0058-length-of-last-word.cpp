class Solution {
public:
    int lengthOfLastWord(string s) {
        auto end = s.find_last_not_of(" ");
        s = s.substr(0,end+1);
        auto start = s.find_last_of(" ");
        return s.length()-start-1;
    }
};