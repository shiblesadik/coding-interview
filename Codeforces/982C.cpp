#include <bits/stdc++.h>
using namespace std;

int n, u, v, ans = 0;
vector<int> graph[100002];

int dfs(int src, int parent) {
	int child = 0, retChild = 1;
	for (int i: graph[src]) {
		if (i != parent) {
			child = dfs(i, src);
			if (child % 2 == 0) ++ans;
			else retChild += child;
		}
	}
	return retChild;
}

int main(void) {
	scanf("%d", &n);
	for (int i = 1; i < n; ++i) {
		scanf("%d %d", &u, &v);
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	if (n & 1) ans = -1;
	else dfs(1, 0);
	printf("%d", ans);
	return 0;
}