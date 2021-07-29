#include <bits/stdc++.h>
using namespace std;

int n, m, a, b, c, brr[200005], arr[200005];

int main(void) {
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    for (int i = 0; i < n + 2; ++i) scanf("%d", brr + i);
    sort(brr, brr + n);
    long long int sum = 0;
    for (int i = 0; i < n; ++i) sum += brr[i];

  }
  return 0;
}

/// 1 2 3 4 5 6 "7" '8'
