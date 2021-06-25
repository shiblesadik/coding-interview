#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> tree[1001];

int main (void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n;
  for (int i = 2; i <= n; ++i) {
    cin >> m;
    tree[m].push_back(i);
  }
  bool is_spruce = true;
  for (int i  = 1; i <= n; ++i) {
    if (tree[i].size() == 0) continue;
    m = 0;
    for (int j = 0; j < tree[i].size(); ++j) {
      if (tree[tree[i][j]].size() == 0) ++m;
    }
    if (m < 3) {
      is_spruce = false;
      break;
    }
  }
  if (is_spruce) printf("Yes");
  else printf("No");
  return 0;
}


