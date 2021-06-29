#include <bits/stdc++.h>
using namespace std;

int n, m, total = 0, arr[100005] = {0}, v[100005];

int main (void) {
//  ios_base::sync_with_stdio(false);
//  cin.tie(NULL);
//  cout.tie(NULL);
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &v[i]);
  }
  int i = 0, j = 0;
  while (j < n) {
    scanf("%d", &m);
    while (arr[v[i]] == 1) {
      ++i;
    }
    if (v[i] != m) {
      arr[m] = 1;
      ++total;
    } else {
      ++i;
    }
    ++j;
  }
  printf("%d\n", total);
  return 0;
}


