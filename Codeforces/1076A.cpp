#include <bits/stdc++.h>
using namespace std;

int test, n, k, m, total = 0, x = 0, r;
char s[200005];

int main (void) {
//  ios_base::sync_with_stdio(false);
//  cin.tie(NULL);
//  cout.tie(NULL);
  scanf("%d ", &n);
  gets(s);
  x = -1;
  for (int i = 1; i < n; ++i) {
    if (s[i] < s[i - 1]) {
      x = i - 1;
      break;
    }
  }
  if (x == -1) {
    char min_char = 'a';
    x = 0;
    for (int i = 0; i < n; ++i) {
      if (min_char < s[i]) {
        min_char = s[i];
        x = i;
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    if (i == x) continue;
    printf("%c", s[i]);
  }
  return 0;
}

