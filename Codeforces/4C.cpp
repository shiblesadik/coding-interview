#include <bits/stdc++.h>
using namespace std;

int n;
string s;
map<string, int> mp;

int main (void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> s;
    if (mp[s] == 0) {
      cout << "OK" << endl;
      mp[s]++;
    } else cout << s << mp[s]++ << endl;
  }
  return 0;
}

