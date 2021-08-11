#include <bits/stdc++.h>
using namespace std;

int n, t, c = 0;
long long int ones[65536] = {0LL}, cnt = 1LL;

int main(void) {
	ones[0] = 1;
	while (c < 65536) {
		cnt += c + 1LL;
		if (cnt > 2147483647) break;
		ones[++c] = cnt;
	}
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		cnt = lower_bound(ones, ones + c, n) - ones;
		printf("%d\n", ones[cnt] == n ? 1 : 0);
	}
	return 0;
}