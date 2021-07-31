class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int row = mat.size();
        int col = mat[0].size();
        queue<pair<int, int> > q;
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (mat[i][j] == 1) {
                    mat[i][j] = 199999999;
                } else {
                    q.push({i, j});
                }
            }
        }
        pair<int, int> pr;
        while (!q.empty()) {
            pr = q.front();
            q.pop();
            if (pr.first - 1 >= 0 && mat[pr.first - 1][pr.second] > mat[pr.first][pr.second] + 1) {
                q.push({pr.first - 1, pr.second});
                mat[pr.first - 1][pr.second] = mat[pr.first][pr.second] + 1;
            }
            if (pr.first + 1 < row && mat[pr.first + 1][pr.second] > mat[pr.first][pr.second] + 1) {
                q.push({pr.first + 1, pr.second});
                mat[pr.first + 1][pr.second] = mat[pr.first][pr.second] + 1;
            }
            if (pr.second - 1 >= 0 && mat[pr.first][pr.second - 1] > mat[pr.first][pr.second] + 1) {
                q.push({pr.first, pr.second - 1});
                mat[pr.first][pr.second - 1] = mat[pr.first][pr.second] + 1;
            }
            if (pr.second + 1 < col && mat[pr.first][pr.second + 1] > mat[pr.first][pr.second] + 1) {
                q.push({pr.first, pr.second + 1});
                mat[pr.first][pr.second + 1] = mat[pr.first][pr.second] + 1;
            }
        }
        return mat;
    }
};
