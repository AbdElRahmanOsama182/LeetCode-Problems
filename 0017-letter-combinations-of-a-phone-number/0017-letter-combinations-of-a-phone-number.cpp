class Solution {
    void comp(int index, string str, string digits, string phone[], vector<string> &comps){
        if (index>=digits.length())
        {
            if (str.length()>0)
                comps.push_back(str);
            return;            
        }
        for (int i = 0; i < phone[digits.at(index)-'2'].length(); i++)
        {
            str.push_back(phone[digits.at(index)-'2'][i]);
            comp(index+1, str, digits, phone, comps);
            str.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        string phone[] = {"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string> comps;
        comp(0,"", digits, phone, comps);
        return comps;
    }
};