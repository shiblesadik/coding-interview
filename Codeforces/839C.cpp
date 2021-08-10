#include <bits/stdc++.h>
using namespace std;

int n, u, v;
vector<int> paths;
vector<int> graph[100002];

long double dfs(int src, int parent) {
	int cnt = 0;
	long double ans = 0.0;
	for (int i: graph[src]) {
		if (i != parent) {
			ans += dfs(i, src);
			++cnt;
		}
	}
	if (cnt > 0) {
		ans /= cnt;
		ans += 1.0;
	}
	return ans;
}

int main(void) {
	scanf("%d", &n);
	for (int i = 1; i < n; ++i) {
		scanf("%d %d", &u, &v);
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	long double ans = dfs(1, 0);
	printf("%.15Lf\n", ans);
	return 0;
}