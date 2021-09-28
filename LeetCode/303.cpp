#include <bits/stdc++.h>
using namespace std;
class NumArray {
public:
	int tree[4 * 10005];
	int tree_size = 0;

  NumArray(vector<int>& nums) {
  	tree_size = nums.size() - 1;
		build_tree(nums, 1, 0, tree_size);
  }

  void build_tree(vector<int>& nums, int index, int l, int r) {
  	if (l == r) {
  		tree[index] = nums[l];
  		return;
  	}
		build_tree(nums, index << 1, l, (l + r) >> 1);
		build_tree(nums, (index << 1) + 1, ((l + r) >> 1) + 1, r);
		tree[index] = tree[index << 1] + tree[(index << 1) + 1];
  }

  int range_query(int index, int l, int r, int left, int right) {
		if (left > r || right < l) return 0;
		if (left <= l && r <= right) return tree[index];
		if (l == r) return tree[index];
		int left_sum = range_query(index << 1, l, (l + r) >> 1, left, right);
		int right_sum = range_query((index << 1) + 1, ((l + r) >> 1) + 1, r, left, right);
		return left_sum + right_sum;
  }

  int sumRange(int left, int right) {
		return range_query(1, 0, tree_size, left, right);
  }
};

int main(void) {
	return 0;
}