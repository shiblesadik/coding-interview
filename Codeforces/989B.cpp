#include <bits/stdc++.h>
using namespace std;

int n, p;
string s;

int main (void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n >> p;
  cin >> s;
  int row = (n / p) + 5;
  int col = p + 5;
  char mx[row][col];
  for (int i = 0; i < row; ++i) {
    for (int j = 0; j < col; ++j) {
      mx[i][j] = ' ';
    }
  }
  row = col = 0;
  for (int i = 0; i < n; ++i) {
    mx[row][col] = s[i];
    ++col;
    if (col == p) {
      ++row;
      col = 0;
    }
  }
  row = ceil(double(n) / double(p));
  cerr << row << " " << p << endl;
  bool possible = true;
  int one = 0, zero = 0, dot = 0;
  for (int j = 0; j < p; ++j) {
    one = 0, zero = 0, dot = 0;
    for (int i = 0; i < row; ++i) {
      if (mx[i][j] == '1') ++one;
      else if (mx[i][j] == '0') ++zero;
      else if (mx[i][j] == '.') ++dot;
    }
    if (dot > 0) {
      for (int i = 0; i < row; ++i) {
        if (mx[i][j] == '.') {
          if (one > 0) {
            mx[i][j] = '0';
          }else if (zero > 0) {
            mx[i][j] = '1';
          } else {
            mx[i][j] = '1';
            ++one;
          }
        }
      }
    }
  }
  possible = true;
  for (int j = 0; j < p; ++j) {
    one = 0, zero = 0, dot = 0;
    for (int i = 0; i < row; ++i) {
      if (mx[i][j] == '1') ++one;
      else if (mx[i][j] == '0') ++zero;
    }
    if (one > 0 && zero > 0) {
      possible = false;
      break;
    }
  }
  if (!possible) {
    for (int i = 0; i < row; ++i) {
      for (int j = 0; j < p; ++j) {
        if (mx[i][j] == '0' || mx[i][j] == '1') {
          printf("%c", mx[i][j]);
        } else {
          break;
        }
      }
    }
  } else {
    printf("No");
  }

  return 0;
}



