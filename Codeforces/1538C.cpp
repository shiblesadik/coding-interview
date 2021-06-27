#include <bits/stdc++.h>
using namespace std;

int test, n, l ,r, arr[200005] = {0}, low = 0, high = 0;
long long int m = 0;

int main (void) {
//  ios_base::sync_with_stdio(false);
//  cin.tie(NULL);
//  cout.tie(NULL);
  scanf("%d", &test);
  while (test--) {
    scanf("%d %d %d", &n, &l, &r);
    for (int i = 0 ; i < n; ++i) {
      scanf("%d", &arr[i]);
    }
    sort(arr, arr + n);
    m = 0;
    for (int i = 0; i < n; ++i) {
      if (arr[i] + arr[i] > r) break;
      low = lower_bound(arr + i + 1, arr + n, l - arr[i]) - arr;
      high = upper_bound(arr + i + 1, arr + n, min(arr[n - 1], r - arr[i])) - arr - 1;
//      if (high >= n) high = n - 1;
//      cout << l - arr[i] << " " << min(arr[n - 1], r- arr[i]) << endl;
//      cout << i << " " << low << " " << high << endl;
//      cout << arr[i] << " " << arr[low] << " " << arr[high] << endl << endl;
      if (low > high) continue;
//      cout << low << " " << high << endl;
//      cout << "value: " << arr[i] << " ";
//      for (int j = low; j <= high; ++j) {
//        cout << arr[j] << " ";
//      }
//      cout << endl;
      m += (high - low + 1);
//      cout << m << endl;
    }
    printf("%lld\n", m);
  }
  return 0;
}


