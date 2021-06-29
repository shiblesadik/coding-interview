#include <bits/stdc++.h>
using namespace std;

int test, n, m, low = 0, high = 0, l, r, d;
int occr[10][1000005], arr[1000005];

int f(int num) {
  if (num == 0) return 1;
  else return num;
}

int g(int num) {
  int ret = 1;
  while (num > 0) {
    if (num % 10 == 0) {
      ret *= 1;
    } else {
      ret *= (num % 10);
    }
    num /= 10;
  }
  if (ret > 9) return arr[ret];
  else return ret;
}

int main (void) {
//  ios_base::sync_with_stdio(false);
//  cin.tie(NULL);
//  cout.tie(NULL);
  for (int i = 1; i <= 1000000; ++i) {
    m = g(i);
    arr[i] = m;
    for (int j = 1; j <= 9; ++j) {
      if (m == j) {
        occr[j][i] = occr[j][i - 1] + 1;
      } else {
        occr[j][i] = occr[j][i - 1];
      }
    }
  }
  scanf("%d", &test);
  while (test--) {
    scanf("%d %d %d", &l ,&r, &d);
    printf("%d\n", occr[d][r] - occr[d][l - 1]);
  }
  return 0;
}


