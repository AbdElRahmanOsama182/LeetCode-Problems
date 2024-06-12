class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> a;
        int count=0, minR=0, minC=0, maxR=matrix.size()-1, maxC=matrix[0].size()-1, total=matrix.size()*matrix[0].size();
        while (count<total)
        {
            for (int i = minC; i <= maxC&& count<total; i++)
            {
                a.push_back(matrix.at(minR).at(i));
                count++;
            }
            minR++;
            for (int i = minR; i <= maxR&& count<total; i++)
            {
                a.push_back(matrix.at(i).at(maxC));
                count++;
            }
            maxC--;
            for (int i = maxC; i >= minC&& count<total; i--)
            {
                a.push_back(matrix.at(maxR).at(i));
                count++;
            }
            maxR--;
            for (int i = maxR; i >= minR&& count<total; i--)
            {
                a.push_back(matrix.at(i).at(minC));
                count++;
            }
            minC++;
            
        }
        return a;
    }
};