#include <bits/stdc++.h>
using namespace std;

int n, m;
string f, s, l, p;
map<string, int> mp;

string to_lower(string word) {
  for (int i = 0; i < word.length(); ++i) {
    if (word[i] >= 'A' && word[i] <= 'Z') {
      word[i] = word[i] + ('a' - 'A');
    }
  }
  return word;
}

int main (void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n;
  cin >> f >> s >> l;
  p = to_lower(l);
  mp[to_lower(f)] = 2;
  mp[p] = 1;
  m = 2;
  for (int i = 1; i < n; ++i) {
    cin >> f >> s >> l;
    f = to_lower(f);
    l = to_lower(l);
    if (mp.find(l) != mp.end()) {
      mp[f] = mp[l] + 1;
      m = max(m, mp[f]);
    }
  }
  cout << m << endl;
  return 0;
}

/// 1 2 3, 1 3 2, 2 1 3, 2 3 1, 3 1 2, 3 2 1
