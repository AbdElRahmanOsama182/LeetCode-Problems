class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(), products.end());
        vector<vector<string>> res;
        string cur = "";
        for (char c : searchWord) {
            cur += c;
            vector<string> suggested;
            auto it = lower_bound(products.begin(), products.end(), cur);
            for (auto i = it; i != products.end() && i->substr(0, cur.size()) == cur && suggested.size() < 3; i++) 
                suggested.push_back(*i);
            res.push_back(suggested);
        }
        return res;
    }
};