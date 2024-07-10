class Solution {
public:
    int minOperations(vector<string>& logs) {
        int ops = 0;
        for (string log : logs) {
            if (log == "../") {
                if (ops > 0)
                    ops--;
            } else if (log != "./") {
                ops++;
            }
        }
        return ops;
    }
};