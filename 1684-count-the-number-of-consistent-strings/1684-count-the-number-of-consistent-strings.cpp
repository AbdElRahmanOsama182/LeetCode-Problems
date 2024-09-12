class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int num = 0;
        int size = words.size();
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < words[i].length(); j++)
            {
                if (allowed.find(words[i].at(j)) == string::npos ){
                    num++;
                    break;
                }
            }
        }
        return size - num;
    }
};