#include <bits/stdc++.h>
using namespace std;

long long int n, k, arr[505] = {0};

int main (void) {
  cin >> n >> k;
  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
  }
  if (k >= n) {
    printf("%lld", n);
    exit(0);
  }
  long long int val = k;
  int pos = 0;
  for (int i = 0; i < n; ++i) {
    val = k;
    pos = i + 1;
    while (val--) {
      if (pos >= n) pos = 0;
      if (arr[pos] > arr[i]) break;
      ++pos;
    }
    if (val < 0) {
      printf("%lld", arr[i]);
      exit(0);
    } else {
      if (val == 0 && i > 0 && arr[i - 1] < arr[i]) {
        printf("%lld", arr[i]);
        exit(0);
      }
    }
  }
  return 0;
}


