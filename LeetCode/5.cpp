class Solution {
public:
  string longestPalindrome(string s) {
    int left, right, max_len = 1, cur_len = 0, index_st = 0, index_end;
    for (int i = 0; i < s.length(); ++i) {
      left = i, right = i + 1;
      cur_len = 0;
      while (left >= 0 && right < s.length()) {
        if (s[left] == s[right]) cur_len += 2;
        else break;
        --left, ++right;
      }
      if (max_len < cur_len) {
        max_len = cur_len;
        index_st = left + 1;
        index_end = right - 1;
      }

      left = i, right = i;
      cur_len = 0;
      while (left >= 0 && right < s.length()) {
        if (s[left] == s[right] && left != right) cur_len += 2;
        else if (s[left] == s[right] && left == right) ++cur_len;
        else break;
        --left, ++right;
      }
      if (max_len < cur_len) {
        max_len = cur_len;
        index_st = left + 1;
        index_end = right - 1;
      }
    }
    string str = "";
    if (max_len == 1) {
      str += s[0];
      return str;
    }
    for (int i = index_st ; i <= index_end && i < s.length(); ++i) {
      str += s[i];
    }
    return str;
  }
};
