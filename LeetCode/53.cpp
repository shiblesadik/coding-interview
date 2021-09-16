class Solution {
public:
  int maxSubArray(vector<int>& nums) {
    int maxx = -10000000, cnt = -10000000;
    for (int i = 0; i < nums.size(); ++i) {
      if (cnt <= 0) {
        cnt = max(cnt, nums[i]);
      } else {
        cnt += nums[i];
      }
      maxx = max(maxx, cnt);
    }
    return maxx;
  }
};