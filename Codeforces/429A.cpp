#include <bits/stdc++.h>
using namespace std;

int n, m, u, v;
vector<int> tree[100005];
vector<int> color_node;
bool visit[100005] = {false};
bool arr[100005] = {false}, goal[100005] = {false};

void dfs(int node, int level, int odd, int even) {
  visit[node] = true;
  bool value;
  if (level % 2 == 1) {
    value = arr[node];
    if (odd % 2 == 1) {
      value = !value;
    }
    if (value != goal[node]) {
      ++odd;
      color_node.push_back(node);
    }
  } else {
    value = arr[node];
    if (even % 2 == 1) {
      value = !value;
    }
    if (value != goal[node]) {
      ++even;
      color_node.push_back(node);
    }
  }
//  cout << "value:: " << node << " " << value << " " << odd << " " << even << endl;
  sort(tree[node].begin(), tree[node].end());
  for (auto child: tree[node]) {
    if (!visit[child]) {
      dfs(child, level + 1, odd, even);
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
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &m);
    if (m == 1) arr[i] = true;
    else arr[i] = false;
  }
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &m);
    if (m == 1) goal[i] = true;
    else goal[i] = false;
  }
  dfs(1, 1, 0, 0);
  sort(color_node.begin(), color_node.end());
  printf("%d\n", color_node.size());
  for (auto node: color_node) {
    printf("%d\n", node);
  }
  return 0;
}
/**
10
1 10
1 9
10 2
10 3
3 7
3 8
9 4
9 5
5 6
1 0 1 1 0 1 0 1 0 1
0 0 0 0 0 0 0 0 0 0

30
2 1
3 2
4 3
5 3
6 5
7 3
8 3
9 2
10 3
11 2
12 11
13 6
14 4
15 5
16 11
17 9
18 14
19 6
20 2
21 19
22 9
23 19
24 20
25 14
26 22
27 1
28 6
29 13
30 27
1 0 1 1 1 1 0 1 0 0 1 0 0 0 1 0 0 1 0 1 0 0 1 0 0 1 1 1 1 0
0 1 0 1 1 1 0 0 1 1 0 1 1 1 0 1 1 1 1 0 1 0 0 1 0 1 1 0 0 0
**/
