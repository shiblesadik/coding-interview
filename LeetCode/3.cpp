class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<char> st;
        int i = 0, j = 0, max_len = 0;
        while (j < s.length()) {
            if (st.find(s[j]) != st.end()) {
                st.erase(s[i]);
                ++i;
            } else {
                st.insert(s[j]);
                max_len = max(max_len, j - i + 1);
                ++j;
            }
        }
        return max_len;
    }
};
