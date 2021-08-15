class Solution {
public:
  int removeDuplicates(vector<int>& nums) {
    int cnt = 1, l = 1, r = 1;
    while (l < nums.size() && r < nums.size()) {
      if (nums[l] == nums[r]) {
        if (nums[l] == nums[l - 1]) {
          if (cnt < 2) {
            ++cnt;
            ++l, ++r;
          } else {
            ++r;
          }
        } else {
          cnt = 1;
          ++l, ++r;
        }
      } else {
        if (nums[l - 1] == nums[r]) {
          if (cnt >= 2) {
            ++r;
          } else {
            nums[l] = nums[r];
            ++cnt;
            ++l, ++r;
          }
        } else {
          cnt = 1;
          nums[l] = nums[r];
          ++l, ++r;
        }
      }
    }
    return l;
  }
};