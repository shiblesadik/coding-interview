#include <bits/stdc++.h>
using namespace std;

int n, m, arr[100005];
bool take[100005] = {false};
map<int, int> mp;
vector<int> to_be_cleared;

int main (void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; ++i) {
    scanf("%d", &arr[i]);
  }
  for (int i = 0; i < m; ++i) {
    mp[arr[i]]++;
    if (mp.size() == n) {
      take[i] = true;
      to_be_cleared.clear();
      for (auto it: mp) {
        to_be_cleared.push_back(it.first);
      }
      for (auto it: to_be_cleared) {
        if (mp[it] == 1) {
          mp.erase(it);
        } else {
          mp[it]--;
        }
      }
    }
  }
  for (int i = 0; i < m; ++i) {
    cout << take[i];
  }
  return 0;
}

