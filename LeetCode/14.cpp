class Solution {
public:
  string longestCommonPrefix(vector<string>& strs) {
    if (strs.size() == 1) return strs[0];
    string prefix = "";
    bool same = true;
    for (int j = 0; j < strs[0].size(); ++j) {
      for (int i = 1; i < strs.size(); ++i) {
        if (strs[i].size() <= j || strs[i][j] != strs[i - 1][j]) {
          same = false;
          break;
        }
      }
      if (!same) break;
      else prefix += strs[0][j];
    }
    return prefix;
  }
};
