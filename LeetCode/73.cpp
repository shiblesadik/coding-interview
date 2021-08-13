class Solution {
public:
  void setZeroes(vector<vector<int>>& matrix) {
    bool first_row = false;
    int i, j;
    
    for (j = 0; j < matrix[0].size(); ++j) {
      if (matrix[0][j] == 0) {
        first_row = true;
        break;
      }
    }
    
    for (i = 1; i < matrix.size(); ++i) {
      for (j = 0; j < matrix[i].size(); ++j) {
        if (matrix[i][j] == 0) {
          matrix[0][j] = 0;
          matrix[i][0] = 0;
        }
      }
    }
    
    for (j = 1; j < matrix[0].size(); ++j) {
      if (matrix[0][j] != 0) continue;
      for (i = 0; i < matrix.size(); ++i) {
        matrix[i][j] = 0;
      }
    }
    
    for (i = 1; i < matrix.size(); ++i) {
      if (matrix[i][0] != 0) continue;
      for (j = 0; j < matrix[i].size(); ++j) {
        matrix[i][j] = 0;
      }
    }
    
    if (matrix[0][0] == 0) {
      for (i = 0; i < matrix.size(); ++i) matrix[i][0] = 0;
    }
    
    if (first_row) {
      for (j = 0; j < matrix[0].size(); ++j) matrix[0][j] = 0;
    }
  }
};