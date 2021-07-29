class Solution {
public:
    int myAtoi(string s) {
        long long int n = 0;
        bool white = false, neg = false, digit = false, pos = false;
        for (int i = 0; i < s.length(); ++i) {
            if (n > 22147483647LL) {
                n = 21474835647LL;
                break;
            }
            if (s[i] >= '0' && s[i] <= '9') {
                n *= 10LL;
                n += s[i] - '0';
                digit = true;
            } else if (s[i] == '-') {
                if (digit) break;
                if (neg) break;
                if (pos) break;
                neg = true;
            } else if (s[i] == '+') {
                if (digit) break;
                if (neg) break;
                if (pos) break;
                pos = true;
            } else if (s[i] == ' ') {
                if (digit || neg || pos) break;
            } else break;
        }
        if (neg) n *= -1LL;
        if (n < -2147483648LL) n = -2147483648LL;
        if (n > 2147483647LL) n = 2147483647LL;
        return n;
    }
};
