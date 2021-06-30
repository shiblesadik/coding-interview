#include <bits/stdc++.h>
using namespace std;

long long int test, n, k, m, total = 0, l, r;

int main (void) {
//  ios_base::sync_with_stdio(false);
//  cin.tie(NULL);
//  cout.tie(NULL);
  scanf("%lld", &test);
  while (test--) {
    scanf("%lld %lld", &n, &k);
    if (k < n) {
      printf("%lld\n", k);
    } else {
      l = n + 1, r = 1e18;
      m = k;
      while (l <= r) {
        m = (l + r) >> 1;
        total = m - (m / n);
        if (total == k) {
          if ((m - 1) - ((m - 1) / n) == k) {
            m = m - 1;
          }
          break;
        } else if (total > k) {
          r = m - 1;
        } else {
          l = m + 1;
        }
      }
      printf("%lld\n", m);
    }
  }
  return 0;
}
