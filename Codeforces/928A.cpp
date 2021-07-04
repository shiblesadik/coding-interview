#include <bits/stdc++.h>
using namespace std;

int test, n, k, m, total = 0, x = 0, r;
char s[51], arr[1001][51];

void convert_str(char *a, int len) {
  for (int i = 0; i < len; ++i) {
    if (a[i] == '0') a[i] = 'O';
    if (a[i] == '1' || a[i] == 'l' || a[i] == 'I' || a[i] == 'i') a[i] = 'l';
    if (a[i] >= 'A' && a[i] <= 'Z') a[i] = a[i] + ('a' - 'A');
  }
}

bool is_valid_login(char *a, int len_a, char *b, int len_b) {
  if (len_a != len_b) return false;
  for (int i = 0; i < len_a; ++i) {
    if (a[i] != b[i]) return false;
  }
  return true;
}

int main (void) {
//  ios_base::sync_with_stdio(false);
//  cin.tie(NULL);
//  cout.tie(NULL);
  gets(s);
  m = strlen(s);
  convert_str(s, m);
  scanf("%d ", &n);
  bool possible = false;
  for (int i = 0; i < n; ++i) {
    gets(arr[i]);
    x = strlen(arr[i]);
    convert_str(arr[i], x);
    possible = possible | is_valid_login(s, m, arr[i], x);
  }
  if (possible) printf("No");
  else printf("Yes");
  return 0;
}


