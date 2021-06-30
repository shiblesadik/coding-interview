#include <bits/stdc++.h>
using namespace std;

int test, n, k, m, total = 0, l, r, sum[3][200005], one, two, three;
char s[200005];

int main (void) {
//  ios_base::sync_with_stdio(false);
//  cin.tie(NULL);
//  cout.tie(NULL);
  scanf("%d ", &test);
  while (test--) {
    gets(s);
    n = strlen(s);
    sum[0][0] = sum[1][0] = sum[2][0] = 0;
    if (s[0] == '1') ++sum[0][0];
    else if (s[0] == '2') ++sum[1][0];
    else ++sum[2][0];
    for (int i = 1; i < n; ++i) {
      sum[0][i] = sum[0][i - 1];
      sum[1][i] = sum[1][i - 1];
      sum[2][i] = sum[2][i - 1];
      if (s[i] == '1') ++sum[0][i];
      else if (s[i] == '2') ++sum[1][i];
      else ++sum[2][i];
    }
    total = 1e9;
    for (int i = 0; i < n - 2; ++i) {
      l = i, r = n - 1;
      while (r - i + 1 >= 3 && l <= r) {
        m = (l + r) >> 1;
        if (i == 0) {
          one = two = three = 0;
        } else {
          one = sum[0][i - 1];
          two = sum[1][i - 1];
          three = sum[2][i - 1];
        }
        if (sum[0][m] - one >= 1 && sum[1][m] - two >= 1 && sum[2][m] - three >= 1) {
          total = min(total, m - i + 1);
          r = m - 1;
        } else {
          l = m + 1;
        }
      }
    }
    if (total == 1e9) total = 0;
    printf("%d\n", total);
  }
  return 0;
}
