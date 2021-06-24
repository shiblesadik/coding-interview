#include <bits/stdc++.h>
using namespace std;

int m, x, y, cols, rows;
long long int n, total = 0;
bool col[100005] = {false}, row[100005] = {false};

int main (void) {
  scanf("%lld", &n);
  scanf("%d", &m);
  rows = (int) n;
  cols = rows;
  total = (n * n);
  for (int i = 0; i < m; ++i) {
    scanf("%d %d", &x, &y);
    if (!row[x] && !col[y]) {
      total -= (cols + rows) - 1;
      row[x] = true;
      col[y] = true;
      --rows, --cols;
    } else if (!row[x] && col[y]) {
      row[x] = true;
      total -= cols;
      --rows;
    } else if (!col[y] && row[x]) {
      col[y] = true;;
      total -= rows;
      --cols;
    }
    printf("%lld ", total);
  }
  return 0;
}

