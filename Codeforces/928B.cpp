#include <bits/stdc++.h>
using namespace std;

int test, n, arr[1000006] = {0}, pos, m;
long long int ans = 0;
string s;
map<int, vector<int>> mp, mp_ex;

int main (void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;
  mp.clear();
  for (int i = 1; i <= n; ++i) {
    cin >> arr[i];
    mp[arr[i]].push_back(i);
  }
  cin >> s;
  m = n << 1;
  mp_ex.clear();
  for (int i = 0; i < m; ++i) {
    if (s[i] == '0') {
      pos = mp.begin()->second[0];
      mp_ex[arr[pos] * -1].push_back(pos);
      mp[arr[pos]].erase(mp[arr[pos]].begin());
      if (mp[arr[pos]].size() == 0) {
        mp.erase(arr[pos]);
      }
    } else {
      pos = mp_ex.begin()->second[0];
      mp_ex[arr[pos] * -1].erase(mp_ex[arr[pos] * -1].begin());
      if (mp_ex[arr[pos] * -1].size() == 0) {
        mp_ex.erase(arr[pos] * -1);
      }
    }
    cout << pos << " ";
  }
  return 0;
}
