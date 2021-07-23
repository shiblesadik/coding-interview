#include <bits/stdc++.h>
using namespace std;

int n, m, a, b, c, test, g[3][3] = {0}, ans = 0, arr[4], maxx = 0;

int main(void) {
  scanf("%d", &test);
  for (int t = 1; t <= test; ++t) {
    g[1][1] = 0;
    ans = 0;
    scanf("%d %d %d", &g[0][0], &g[0][1], &g[0][2]);
    scanf("%d %d", &g[1][0], &g[1][2]);
    scanf("%d %d %d", &g[2][0], &g[2][1], &g[2][2]);

    if (g[0][1] - g[0][0] == g[0][2] - g[0][1]) ++ans;
    if (g[2][1] - g[2][0] == g[2][2] - g[2][1]) ++ans;

    if (g[1][0] - g[0][0] == g[2][0] - g[1][0]) ++ans;
    if (g[1][2] - g[0][2] == g[2][2] - g[1][2]) ++ans;

    arr[0] = abs(g[0][0] - g[2][2]);
    arr[1] = abs(g[0][2] - g[2][0]);
    arr[2] = abs(g[0][1] - g[2][1]);
    arr[3] = abs(g[1][0] - g[1][2]);

    maxx = 0;
    for (int i = 0; i < 4; ++i) {
      if (arr[i] % 2 != 0) continue;
      for (int j = (arr[i] / 2) - 1; j <= (arr[i] / 2) + 1; ++j) {
        c = 0;
        g[1][1] = j;
        if (arr[i] == 0) {
          if (i == 0) g[1][1] = g[0][0];
          if (i == 1) g[1][1] = g[0][2];
          if (i == 2) g[1][1] = g[0][1];
          if (i == 3) g[1][1] = g[1][0];
        }

        if (g[1][1] - g[0][0] == g[2][2] - g[1][1]) ++c;
        if (g[1][1] - g[0][2] == g[2][0] - g[1][1]) ++c;

        if (g[1][1] - g[1][0] == g[1][2] - g[1][1]) ++c;
        if (g[1][1] - g[0][1] == g[2][1] - g[1][1]) ++c;
        maxx = max(maxx, c);
      }
      c = 0;
      g[1][1] = arr[i];
      if (g[1][1] - g[0][0] == g[2][2] - g[1][1]) ++c;
      if (g[1][1] - g[0][2] == g[2][0] - g[1][1]) ++c;

      if (g[1][1] - g[1][0] == g[1][2] - g[1][1]) ++c;
      if (g[1][1] - g[0][1] == g[2][1] - g[1][1]) ++c;
      maxx = max(maxx, c);
    }
    ans += maxx;

    printf("Case #%d: %d\n", t, ans);
  }
  return 0;
}
