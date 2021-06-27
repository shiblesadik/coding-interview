#include <bits/stdc++.h>
using namespace std;

int test, n, sum[1000006] = {0};
long long int ans = 0;
string s;

int main (void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> test;
  while (test--) {
    cin >> n;
    cin >> s;
    sum[0] = s[0] == '*' ? 1 : 0;
    for (int i = 1; i < n; ++i) {
      sum[i] = sum[i - 1] + (s[i] == '*' ? 1 : 0);
    }
    ans = 0;
    for (int i = 0; i < n; ++i) {
      if (s[i] == '*') continue;
      ans += min(sum[i], sum[n - 1] - sum[i]);
    }
    cout << ans << endl;
  }
  return 0;
}
/**
*.*...*.**
*.*...**.*
*.*...***.
*..*..***.
.*.*..***.
..**..***.
..*.*.***.
..*..****.
...*.****.
....*****.

*1*222*2**
**/
