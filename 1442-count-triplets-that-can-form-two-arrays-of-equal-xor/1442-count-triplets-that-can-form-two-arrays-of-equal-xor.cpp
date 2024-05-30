class Solution {
public:
    int countTriplets(vector<int>& arr) {
        vector<int> prefix(arr.size() + 1);
        for(int i = 0; i < arr.size(); i++)
            prefix[i + 1] = prefix[i] ^ arr[i];
        
        int res = 0;
        for(int i = 0; i < arr.size()+1; i++){
            for(int j = i + 1; j < arr.size()+1; j++){
                if (prefix[i] == prefix[j])
                    res += j - i - 1;
            }
        }
        return res;
    }
};