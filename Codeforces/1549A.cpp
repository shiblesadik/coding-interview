#include <bits/stdc++.h>
using namespace std;

int t, cnt = 0;
int a, b, p, x, y;

bitset<100005> pr = 0;
int prime[100005] = {0};

int main(void) {
  pr[1] = true;
  for (int i = 4; i <= 100000; i += 2) pr[i] = true;
  for (int i = 3; (i * i) <= 100000; ++i) {
    if (pr[i] == true) continue;
    for (int j = (i * i); j <= 100000; j += i) {
      pr[j] = true;
    }
  }

  for (int i = 2; i <= 100000; ++i) {
    if (!pr[i]) {
      prime[cnt++] = i;
    }
  }

  scanf("%d", &t);
  while (t--) {
    scanf("%d", &p);
    x = p - 1;
    for (int i = 0; i < cnt && prime[i] <= x; ++i) {
      if (x % prime[i] == 0) {
        a = prime[i];
        if (prime[i] * prime[i] == x) b = x;
        else b = x / prime[i];
        printf("%d %d\n", a, b);
        break;
      }
    }
  }
  return 0;
}
