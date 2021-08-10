#include <bits/stdc++.h>
using namespace std;

int n, m, a, b, c;
long long int dp[4][300001];
char s[300005];

long long int f(int pos, int pre) {
	if (pos >= n) return 0LL;
	if (dp[pre][pos] != -1LL) return dp[pre][pos];
	long long int ret = 0LL;
	pre *= 10;
	pre += (s[pos] - '0');
	pre %= 4;
	if (pre == 0) ++ret;
	ret += f(pos + 1, pre);
	ret += f(pos + 1, 0);
	return dp[pre][pos] = ret;
}

int main(void) {
	gets(s);
	n = strlen(s);
	memset(dp, -1LL, sizeof dp);
	long long int ans = f(0, 0);
	printf("%lld\n", ans);
	return 0;
}