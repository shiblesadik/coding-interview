class Solution {
public:
  string convert(string s, int numRows) {
    if (numRows == 1) return s;
    char mx[numRows + 1][s.length() + 1];
    for (int i = 0; i < numRows; ++i) {
      for (int j = 0; j < s.length(); ++j) {
        mx[i][j] = ' ';
      }
    }
    string str = "";
    int cnt = 0, row = 0, col = 0;
    bool inv = false;
    while (cnt < s.length()) {
      mx[row][col] = s[cnt];

      if (row == numRows - 1) {
        inv = true;
      }
      if (row == 0) {
        inv = false;
      }
      if (inv) {
        --row;
        ++col;
      }
      else ++row;
      ++cnt;
    }
    for (int i = 0; i < numRows; ++i) {
      for (int j = 0; j < s.length(); ++j) {
        if (mx[i][j] != ' ') str += mx[i][j];
      }
    }
    return str;
  }
};
