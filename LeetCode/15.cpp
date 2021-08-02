class Solution {
public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    unordered_map<int, vector<int> > index;
    for (int i = 0 ; i < nums.size(); ++i) {
      index[nums[i]].push_back(i);
    }
    vector<vector<int> > initTriplets;
    unordered_set<int> i_index, j_index;
    int sum = 0, req = 0;
    for (int i = 0; i < nums.size(); ++i) {
      if (i_index.find(nums[i]) != i_index.end()) continue;
      else i_index.insert(nums[i]);
      j_index.clear();
      for (int j = i + 1; j < nums.size(); ++j) {
        if (j_index.find(nums[j]) != j_index.end()) continue;
        else j_index.insert(nums[j]);
        sum = nums[i] + nums[j];
        req = sum * -1;
        if (index.find(req) != index.end()) {
          int k = upper_bound(index[req].begin(), index[req].end(), j) - index[req].begin();
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
