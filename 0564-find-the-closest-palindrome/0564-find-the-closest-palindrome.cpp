class Solution {
public:
    string nearestPalindromic(string n) {
        long long num = stoll(n);
        long long prev = prevPalindrome(num);
        long long next = nextPalindrome(num);
        return abs(num - prev) >= abs(num - next) ? to_string(next) : to_string(prev);
    }

    long long toPalindrome(long long &num) {
        string s = to_string(num);
        int n = s.size();
        for (int i = 0; i < n/2; i++) {
            s[n-i-1] = s[i];
        }
        return stoll(s);
    }

    long long prevPalindrome(long long &num) {
        long long l = num, r = 1e18, ans = -1, mid;
        while (l <= r) {
            mid = l + (r-l)/2;
            long long pal = toPalindrome(mid);
            if (pal > num) {
                ans = pal;
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }
        return ans;
    }

    long long nextPalindrome(long long &num) {
        long long l = 0, r = num, ans = -1, mid;
        while (l <= r) {
            mid = l + (r-l)/2;
            long long pal = toPalindrome(mid);
            if (pal < num) {
                ans = pal;
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }
        return ans;
    }
};