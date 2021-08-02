class Solution {
public:
  int largestIsland(vector<vector<int>>& grid) {
    int col[250005];
    int cur_col = 2;

    for (int i = 0; i < 250005; ++i) col[i] = 0;

    queue<pair<int,int>> q;
    int x, y;

    for (int i = 0; i < grid.size(); ++i) {
      for (int j = 0; j < grid.size(); ++j) {
        if (grid[i][j] == 1) {

          grid[i][j] = cur_col;

          q.push({i, j});
          while (!q.empty()) {
            x = q.front().first, y = q.front().second;
            q.pop();
            ++col[grid[x][y]];
            if (x - 1 >= 0 && grid[x - 1][y] == 1) {
              grid[x - 1][y] = grid[x][y];
              q.push({x - 1, y});
            }
            if (x + 1 < grid.size() && grid[x + 1][y] == 1) {
              grid[x + 1][y] = grid[x][y];
              q.push({x + 1, y});
            }
            if (y - 1 >= 0 && grid[x][y - 1] == 1) {
              grid[x][y - 1] = grid[x][y];
              q.push({x, y - 1});
            }
            if (y + 1 < grid.size() && grid[x][y + 1] == 1) {
              grid[x][y + 1] = grid[x][y];
              q.push({x, y + 1});
            }
          }

          ++cur_col;
        }
      }
    }

    int max_value = 1, l = 0, r = 0, u = 0, d = 0, lc = 0, rc = 0, uc = 0, dc = 0;

    for (int i = 0; i < cur_col; ++i) max_value = max(max_value, col[i]);

    for (int i = 0; i < grid.size(); ++i) {
      for (int j = 0; j < grid.size(); ++j) {
        if (grid[i][j] == 0) {
          l = 0, r = 0, u = 0, d = 0, lc = 0, rc = 0, uc = 0, dc = 0;
          if (i - 1 >= 0) {
            uc = grid[i - 1][j];
            u = col[uc];
          }
          if (i + 1 < grid.size() && grid[i + 1][j] != uc) {
            dc = grid[i + 1][j];
            d = col[dc];
          }
          if (j - 1 >= 0 && grid[i][j - 1] != uc && grid[i][j - 1] != dc) {
            lc = grid[i][j - 1];
            l = col[lc];
          }
          if (j + 1 < grid.size() && grid[i][j + 1] != uc && grid[i][j + 1] != dc && grid[i][j + 1] != lc) {
            rc = grid[i][j + 1];
            r = col[rc];
          }
          max_value = max(max_value, l + r + u + d + 1);
        }
      }
    }

    return max_value;
  }
};


/**
[[1,0],[0,1]]
[[1,1,1,1,0],[0,0,0,0,1],[1,1,1,1,1],[0,0,0,1,0],[1,1,1,1,1]]
**/
