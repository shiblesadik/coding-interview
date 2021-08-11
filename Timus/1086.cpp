#include <bits/stdc++.h>
using namespace std;

int n, t, primes[15001], c = 0;
bool v[200001] = {false};

int main(void) {
	for (int i = 4; i < 200000; i += 2) {
		v[i] = true;
	}
	for (int i = 3; i * i < 200000; i += 2) {
		if (v[i]) continue;
		for (int j = i * i; j < 200000; j += i) {
			v[j] = true;
		}
	}
	for (int i = 2; i < 200000; ++i) {
		if (!v[i]) {
			primes[++c] = i;
		}
		if (c == 15000) break;
	}
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		printf("%d\n", primes[n]);
	}
	return 0;
}