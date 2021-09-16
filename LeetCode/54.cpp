class Solution {
public:
  vector<int> spiralOrder(vector<vector<int>>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
    int total = n * m;
    bool visit[n][m];
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        visit[i][j] = false;
      }
    }
    int direction = 1;
    int x = 0, y = 0;
    vector<int> v;
    while (total--) {
      visit[x][y] = true;
      v.push_back(matrix[x][y]);
      if (direction == 1) {
        if (y == m - 1) {
          direction = 2;
          ++x;
        } else if (visit[x][y + 1] == true) {
          direction = 2;
          ++x;
        } else {
          ++y;
        }
      } else if (direction == 2) {
        if (x == n - 1) {
          direction = 3;
          --y;
        } else if (visit[x + 1][y] == true) {
          direction = 3;
          --y;
        } else {
          ++x;
        }
      } else if (direction == 3) {
        if (y == 0) {
          direction = 4;
          --x;
        } else if (visit[x][y - 1] == true) {
          direction = 4;
          --x;
        } else {
          --y;
        }
      } else if (direction == 4) {
        if (visit[x - 1][y] == true) {
          direction = 1;
          ++y;
        } else {
          --x;
        }
      } else {
        break;
      }
    }
    return v;
  }
};