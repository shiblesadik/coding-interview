#include <bits/stdc++.h>
using namespace std;

int n, m, arr[200005], brr[200005];

int main (void) {
//  ios_base::sync_with_stdio(false);
//  cin.tie(NULL);
//  cout.tie(NULL);
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; ++i) {
    scanf("%d", & arr[i]);
  }
  for (int i = 0; i < m; ++i) {
    scanf("%d", & brr[i]);
  }
  sort(arr, arr + n);
  int pos = 0;
  for (int i = 0; i < m; ++i) {
    pos = upper_bound(arr, arr + n, brr[i]) - arr;
    printf("%d ", pos);
  }
  return 0;
}
