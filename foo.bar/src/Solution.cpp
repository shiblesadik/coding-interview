#define NDEBUG
#include <bits/stdc++.h>
using namespace std;

long long  n, m, x, y;
long long int dp[1001][1001] = {-1};

void fun(int a, int b) {
  if (a > 1000 || b > 1000) return;
  if (a + b <= 1000 && dp[a + b][b] > dp[a][b]) {
    dp[a + b][b] = dp[a][b] + 1;
    fun(a + b, b);
  } else if (a + b > 1000) {
    ++n;
  } else {
    ++y;
  }
  if (b + a <= 1000 && dp[a][b + a] > dp[a][b]) {
    dp[a][b + a] = dp[a][b] + 1;
    fun(a, b + a);
  } else if (b + a > 1000) {
    ++m;
  } else {
    ++x;
  }
}

int main (void) {
  for (int i = 0; i <= 1000; ++i) {
    for (int j = 0; j <= 1000; ++j) {
      dp[i][j] = 1999999999;
    }
  }
  dp[1][1] = 0;
  fun(1, 1);
  for (int i = 1; i <= 100; ++i) {
    for (int j = i + 1; j <= 100; ++j) {
      printf("%d %d %d\n", i, j, dp[i][j]);
    }
  }
  return 0;
}
