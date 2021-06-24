#include <bits/stdc++.h>
using namespace std;

int n, m, arr[100005];

int main (void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", & arr[i]);
  }
  sort(arr, arr + n);
  int total = 0, first_ite = 0, last_ite = 0;
  while (last_ite < n) {
    if (arr[last_ite] == -1) {
      ++last_ite;
      continue;
    }
    if (first_ite == last_ite) {
      ++last_ite;
      continue;
    }
    if (arr[first_ite] < arr[last_ite]) {
      ++total;
      ++first_ite;
      ++last_ite;
    } else {
      ++last_ite;
    }
  }
  cout << total << endl;
  return 0;
}
/// 1 1 1 3 5 5 10
