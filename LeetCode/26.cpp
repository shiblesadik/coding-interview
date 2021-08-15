class Solution {
public:
  int removeDuplicates(vector<int>& nums) {
    if (nums.size() < 1) return 0;
    int l = 1, r = 1;
    while (r < nums.size()) {
      if (nums[l - 1] == nums[r]) ++r;
      else {
        nums[l] = nums[r];
        ++l, ++r;
      }
    }
    return l;
  }
};