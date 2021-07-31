class Solution {
public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    unordered_map<int, vector<int> > index;
    for (int i = 0 ; i < nums.size(); ++i) {
      index[nums[i]].push_back(i);
    }
    vector<vector<int> > initTriplets;
    set<int> i_index, j_index;
    int sum = 0, req = 0;
    for (int i = 0; i < nums.size(); ++i) {
      for (int j = i + 1; j < nums.size(); ++j) {
        sum = nums[i] + nums[j];
        req = sum * -1;
        // printf("%d %d :: %d %d %d\n", i, j, nums[i], nums[j], req);
        if (index.find(req) != index.end()) {
          int k = upper_bound(index[req].begin(), index[req].end(), j) - index[req].begin();
          // printf("%d %d %d\n", i, j, k < index[req].size() ? index[req][k]: 999);
          if (k < index[req].size()) {
            k = index[req][k];
            vector<int> v{nums[i], nums[j] , nums[k]};
            sort(v.begin(), v.end());
            initTriplets.push_back(v);
          }
        }
      }
    }
    sort(initTriplets.begin(), initTriplets.end());
    vector<vector<int> > triplets;
    if (initTriplets.size() > 0) {
      triplets.push_back(initTriplets[0]);
    }
    for (int i = 1; i < initTriplets.size(); ++i) {
      if (initTriplets[i][0] != initTriplets[i - 1][0]) {
        triplets.push_back(initTriplets[i]);
      } else if (initTriplets[i][1] != initTriplets[i - 1][1]) {
        triplets.push_back(initTriplets[i]);
      } else if (initTriplets[i][2] != initTriplets[i - 1][2]) {
        triplets.push_back(initTriplets[i]);
      }
    }
    return triplets;
  }
};
