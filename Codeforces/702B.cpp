#include <bits/stdc++.h>
using namespace std;

long long int n, val, maxx = 0LL;
map<long long int, long long int> mp;
long long int power[64] = {1LL}, sum;

int main (void) {
  for (long long int i = 1; i <= 60; ++i) {
    power[i] = (1LL << i);
  }
  scanf("%lld", &n);
  for (long long int i = 0LL; i < n; ++i) {
    scanf("%lld", &val);
    ++mp[val];
    maxx = max(maxx, val);
  }
  long long int ans = 0LL;
  long long int pre = -1LL;
  for (auto ite: mp) {
    if (pre != -1) {
      mp.erase(pre);
    }
    pre = ite.first;
    for (long long int i = 0LL; i <= 32; ++i) {
      sum = power[i] - ite.first;
      if (sum == ite.first) {
        ans += (ite.second * (ite.second - 1LL)) / 2LL;
      } else if (sum > 0LL) {
        if (mp.find(sum) != mp.end()) {
          ans += mp[sum] * ite.second;
        }
      }
    }
  }
  printf("%lld\n", ans);
  return 0;
}
