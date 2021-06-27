#include <bits/stdc++.h>
using namespace std;

int n, m, u, v;
long long int red = 0, blue = 0, ans = 0;
vector<int> tree[100005];
bool visit[100005] = {false};

void dfs(int node, bool color) {
  visit[node] = true;
  if (color) ++blue;
  else ++red;
//  cout << red << " " << blue << endl;
//  sort(tree[node].begin(), tree[node].end());
  for (auto child: tree[node]) {
    if (!visit[child]) {
      dfs(child, !color);
    }
  }
}

int main (void) {
//  ios_base::sync_with_stdio(false);
//  cin.tie(NULL);
//  cout.tie(NULL);
  scanf("%d", &n);
  for (int i = 1; i < n; ++i) {
    scanf("%d %d", &u, &v);
    tree[v].push_back(u);
    tree[u].push_back(v);
  }
  dfs(1, true);
  cout << (red * blue) - (n - 1) << endl;
  return 0;
}

