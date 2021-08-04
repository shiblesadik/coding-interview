class Solution {
public:
  vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> v;
    vector<int> vv;
    for (int i = 0; i < pow(2, nums.size()); ++i) {
      vv.clear();
      for (int j = 0; j < nums.size(); ++j) {
        if ( i & (1 << j)) {
          vv.push_back(nums[j]);
        }
      }
      sort(vv.begin(), vv.end());
      v.push_back(vv);
    }
    sort(v.begin(), v.end());
    vector<vector<int>> vec;
    vec.push_back(v[0]);
    bool same = false;
    for (int i = 1; i < v.size(); ++i) {
      if (v[i].size() == v[i - 1].size()) {
        same = true;
        for (int j = 0; j < v[i].size(); ++j) {
          if (v[i][j] != v[i - 1][j]) {
            same = false;
            break;
          }
        }
        if (!same) {
          vec.push_back(v[i]);
        }
      } else {
        vec.push_back(v[i]);
      }
    }
    return vec;
  }
};
