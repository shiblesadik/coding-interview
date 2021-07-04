#include <bits/stdc++.h>
using namespace std;

struct vpair {
};

int n, s, p, q;
char d;
vector<pair<int, int>> buy, sell;
map<int, int> buy_mp, sell_mp;

int main (void) {
//  ios_base::sync_with_stdio(false);
//  cin.tie(NULL);
//  cout.tie(NULL);
  scanf("%d %d", &n, &s);
  for (int i = 0; i < n; ++i) {
    scanf(" %c %d %d", &d, &p, &q);
    if (d == 'B') {
      buy_mp[p * -1] += q;
    } else {
      sell_mp[p] += q;
    }
  }
  for (auto i: buy_mp) {
    if (buy.size() >= s) break;
    else buy.push_back({i.first * -1, i.second});
  }
  for (auto i: sell_mp) {
    if (sell.size() >= s) break;
    else sell.push_back({i.first, i.second});
  }
  reverse(sell.begin(), sell.end());
  for (auto i: sell) {
    printf("S %d %d\n", i.first, i.second);
  }

  for (auto i: buy) {
    printf("B %d %d\n", i.first, i.second);
  }
  return 0;
}




