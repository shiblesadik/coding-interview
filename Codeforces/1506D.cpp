#include <bits/stdc++.h>
using namespace std;

struct vpair {
  int val, int ocr;
  vpair(int val) {
    this->val = val;
    this->ocr = 1;
  }
};

bool operator< (vpair &a, vpair &b) {
  return a.ocr > b.ocr;
}

int n, arr[200005], t, rm;
vector<int> v;
map<int, int> mp;

int main(void) {
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    mp.clear();
    v.clear();
    for (int i = 0; i < n; ++i) {
      scanf("%d", arr + i);
      mp[arr[i]]++;
    }
    while (mp.size() > 0) {
      rm = -1;
      for (auto i: mp) {
        if (rm != -1) {
          mp.erase(rm);
          rm = -1;
        }
        v.push_back(i.first);
        mp[i.first]--;
        if (i.second <= 1) {
          rm = i.first;
        }
      }
      if (rm != -1) {
        mp.erase(rm);
        rm = -1;
      }
    }
    for (auto it: v) {
      printf("%d ", it);
    }
    puts("");
    int ans = 0;
    int i = 0;
    while (i < n - 1) {
      if (v[i] != v[i + 1]) {
        ans += 2;
        i += 2;
      } else {
        ++i;
      }
    }
    printf("%d\n", (n - ans));
  }
  return 0;
}
