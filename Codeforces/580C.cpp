#include <bits/stdc++.h>
using namespace std;
int n, m, arr[100002] = {0}, u, v;
vector<int> graph[100002];
bitset<100002> visit = 0;

int dfs(int src, int cnt) {	
	visit[src] = true;
	if (arr[src]) ++cnt;
	else cnt = 0;
	if (cnt > m) return 0;
	if (graph[src].size() == 1 && src != 1) return 1;
	int ret = 0;
	for (auto i: graph[src]) {
		if (!visit[i]) ret += dfs(i, cnt);
	}
	return ret;
}

int main(void) {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; ++i) scanf("%d", arr + i);
	for (int i = 1; i < n; ++i) {
		scanf("%d %d", &u, &v);
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	cout << dfs(1, 0) << endl;;
	return 0;
}