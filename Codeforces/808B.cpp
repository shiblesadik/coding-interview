#include <bits/stdc++.h>
using namespace std;

int n, m, total = 0, k;
long double arr[200005] = {0.0};

int main (void) {
//  ios_base::sync_with_stdio(false);
//  cin.tie(NULL);
//  cout.tie(NULL);
  scanf("%d %d", &n, &k);
  for (int i = 1; i <= n; ++i) {
    scanf("%Lfd", &arr[i]);
    arr[i] += arr[i - 1];
  }

  long double sum = 0;

  for (int i = 1; (n - i + 1) >= k; ++i) {
    sum += (arr[i + k - 1] - arr[i - 1]);
  }
  printf("%.10Lf", (sum / (n - k + 1)));
  return 0;
}
