#include <bits/stdc++.h>
using namespace std;

int n, m, arr[100005] = {0}, pos[100005] = {0};
vector<int> break_point;
set<int> st;

int main (void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &m);
    arr[m] = i;
  }
  int total = 0, left = 0;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &m);
    pos[i] = arr[m];
    st.insert(i);
  }
  for (int i = 1; i <= n; ++i) {
    if (pos[i])
  }

  cout << total << endl;
  return 0;
}


