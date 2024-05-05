class Solution {
public:
    int compareVersion(string version1, string version2) {
        int n = version1.size(), m = version2.size();
        int v1 = 0, v2 = 0;
        for (int i = 0, j = 0; i < n || j < m; i++, j++) {
            while (i < n && version1[i] != '.') {
                v1 = 10 * v1 + (version1[i]-'0');
                i++;
            }
            while (j < m && version2[j] != '.') {
                v2 = 10 * v2 + (version2[j]-'0');
                j++;
            }
            if (v1 < v2) return -1;
            else if (v1 > v2) return 1;
            else v1 = v2 = 0;
        }
        return 0;
    }
};