#include <bits/stdc++.h>
using namespace std;

long long int n, k, a, b, ans;
string s;

int main(void) {
	cin >> n >> s;
	k = s.length();
	a = n;
	b = 1;
	while (true) {
		if (n - b * k <= 0) break;
		if (k < n) a *= (n - b * k);
    else a *= (n % k); 
    ++b;
	}
	cout << a << endl;
	return 0;
}