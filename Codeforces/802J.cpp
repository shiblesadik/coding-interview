#include <bits/stdc++.h>
using namespace std;
int n, m, u, v, c;
vector<pair<int, int>> graph[100002];
bitset<100002> visit = 0;

int dfs(int src) {	
	visit[src] = true;
	int ret = 0;
	for (auto i: graph[src]) {
		if (!visit[i.first]) ret = max(ret, dfs(i.first) + i.second);
	}
	return ret;
}

int main(void) {
	scanf("%d", &n);
	for (int i = 1; i < n; ++i) {
		scanf("%d %d %d", &u, &v, &c);
		graph[u].push_back({v, c});
		graph[v].push_back({u, c});
	}
	cout << dfs(0) << endl;;
	return 0;
}