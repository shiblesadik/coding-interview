#include <bits/stdc++.h>
using namespace std;

int n, birth[100002] = {0}, death[100002] = {0}, alive = 0, year = 0;
int years[200004] ={0}, total_alive[200004] = {0};

int main (void) {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d %d", &birth[i], &death[i]);
  }
  sort(birth + 1, birth + n + 1);
  sort(death + 1, death + n + 1);
  int pos = 1, l = 1, r = 1;
  while (l <= n || r <= n) {
    if (death[r] <= birth[l] || l > n) {
      years[pos] = death[r];
      total_alive[pos] = -1;
      ++r;
      ++pos;
    } else {
      years[pos] = birth[l];
      total_alive[pos] = 1;
      ++l;
      ++pos;
    }
  }
  for (int i = 1; i < pos; ++i) {
    total_alive[i] += total_alive[i - 1];
    if (total_alive[i] > alive) {
      alive = total_alive[i];
      year = years[i];
    }
  }
  printf("%d %d", year, alive);
  return 0;
}
