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

long long int f(long long int a, long long int b) {
  if (a == 1 && b == 1) return 0;
  long long int d = b - a;
  if (a % d == 0) {
    assert(d == 1);
    return a / d;
  }
  long long int xx = a / d;
  return 1 + xx + f(a % d, d);
}

int main (void) {
  for (int i = 0; i <= 1000; ++i) {
    for (int j = 0; j <= 1000; ++j) {
      dp[i][j] = 1999999999;
    }
  }
  dp[1][1] = 0;
  fun(1, 1);
  cout << dp[17][104] << endl;
  return 0;
}
