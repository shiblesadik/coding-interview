class Solution {
public:
  vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, vector<int> > mp;
    for (int i = 0; i < nums.size(); ++i) {
      mp[nums[i]].push_back(i);
    }
    int sum;
    vector<int> v;
    for (int i = 0; i < nums.size(); ++i) {
      sum = target - nums[i];
      if (mp.find(sum) != mp.end()) {
        if (nums[i] == sum) {
          if (mp[sum].size() > 1) {
            v.push_back(mp[sum][0]);
            v.push_back(mp[sum][1]);
            break;
          }
        } else {
          v.push_back(i);
          v.push_back(mp[sum][mp[sum].size() - 1]);
          break;
        }
      }
    }
    return v;
  }
};
