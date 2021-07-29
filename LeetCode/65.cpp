class Solution {
public:
    bool isNumber(string s) {
        bool white = false, neg = false, digit = false, pos = false, n = false, e = false, dot = false;
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] >= '0' && s[i] <= '9') {
                digit = true;
                n = true;
            } else if (s[i] == '-') {
                if (digit || neg || pos || dot || e) return false;
                neg = true;
                n = true;
            } else if (s[i] == '+') {
                if (digit || neg || pos || dot || e) return false;
                pos = true;
            } else if (s[i] == 'e' || s[i] == 'E') {
                if (e) return false;
                if (!digit) return false;
                else if (digit && !e) {e = true; n = false;}
                else if (digit && e) return false;
            } else if (s[i] == '.') {
                if (dot) return false;
                else if (digit && !e) {dot = true;}
                else if (digit && e) return false;
                dot = true;
            }
            else return false;
        }
        return n && digit;
    }
};
