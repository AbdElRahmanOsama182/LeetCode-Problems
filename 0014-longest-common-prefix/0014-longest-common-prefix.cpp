class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int size = strs.size();
        if (size==0)
            return "";
        if (size==1)
            return strs[0];
        string comm = "";
        for (int i = 0; i < strs[0].length(); i++)
        {
            bool found = true;
            for (int j = 1; j < size; j++)
            {
                if ((i >= strs[j].length())||(strs[0].at(i)!=strs[j].at(i)))
                {
                    found = false;
                    break;
                }
            }
            if (found)
            {
                comm += strs[0].at(i);
            }
            else
            {
                break;
            }
        }
        return comm;
    }
};