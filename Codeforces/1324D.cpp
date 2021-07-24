#include <bits/stdc++.h>
using namespace std;

int n, arr[200005] = {0}, brr[200005] = {0}, diff[200005] = {0}, l, val;
long long int ans = 0LL;

int main(void) {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) scanf("%d", arr + i);
  for (int i = 0; i < n; ++i) scanf("%d", brr + i);
  for (int i = 0; i < n; ++i) diff[i] = arr[i] - brr[i];
  sort(diff, diff + n);
  for (int i = 0; i < n; ++i) {
    if (diff[i] <= 0) {
      val = abs(diff[i]) + 1;
    } else val = diff[i];
    l = lower_bound(diff + i + 1, diff + n, val) - diff;
    if (l < n) ans += (n - l);
  }
  printf("%lld\n", ans);
  return 0;
}
