class Solution {
public:
  void rotate(vector<int>& nums, int k) {
    if (nums.size() == 0 || k == 0) return;
    k %= nums.size();
    if (k == 0) return;
    k = nums.size() - k;
    int p = nums.size();
    int cur_index = 0, rem = 0, cur_value = nums[0], pre_value = nums[0];
    if (k + k == nums.size()) {
      for (int i = 0; i < k; ++i) {
        nums[i] ^= nums[nums.size() - k + i] ^= nums[i] ^= nums[nums.size() - k + i];
      }
    }
    else {
      while (p--) {
        rem = (cur_index + 1) % k;
        if (rem == 0) rem = nums.size();
        else if (cur_index < k) {
          rem += (nums.size() - k);
        }
        --rem;
        cur_value = nums[rem];
        nums[rem] = pre_value;
        pre_value = cur_value;
        printf("%d %d\n", cur_index, rem);
        for (int i = 0; i < nums.size(); ++i) {
          printf("%d ", nums[i]);
        }
        cout << endl;
        cur_index = rem;
      }
    }
  }
};
