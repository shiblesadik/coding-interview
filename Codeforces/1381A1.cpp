#include <bits/stdc++.h>
using namespace std;

int test, n, m, arr[100005] = {0};
char a[100005], b[100005];
bool a_val = false, b_val = false, first_pos_status = false, current_pos_status = false;
vector<int> taken_pos;

int main (void) {
//  ios_base::sync_with_stdio(false);
//  cin.tie(NULL);
//  cout.tie(NULL);
  scanf("%d", &test);
  while (test--) {
    scanf("%d ", &n);
    gets(a);
    gets(b);
    taken_pos.clear();
    for (int i = n - 1; i >= 0; --i) {
      if (a[i] != b[i]) {
        if (a[0] == b[i]) {
          taken_pos.push_back(1);
          if (a[0] == '0') a[0] = '1';
          else a[0] = '0';
        }
        taken_pos.push_back(i + 1);
        for (int j = 0; j <= i; ++j) {
          if (a[j] == '0') a[j] = '1';
          else a[j] = '0';
        }
        reverse(a, a + i + 1);
      }
    }
    printf("%d", taken_pos.size());
    for (int i: taken_pos) {
      printf(" %d", i);
    }
    printf("\n");
  }
  return 0;
}



