#include <bits/stdc++.h>
using namespace std;

int n, m, arr[100005];
bool [100005] = {false}, take[100005] = {false};

int main (void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; ++i) {
    scanf("%d", &arr[i]);
  }
  int total = 0;
  for (int i = 0; i < m; ++i) {
    if (!take[arr[i]]) {

    }
  }
  return 0;
}

