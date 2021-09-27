#include <bits/stdc++.h>
using namespace std;

class NumArray {
public:
  int arr[30002];
	int tree[220002] = {0};
	int tree_size = 0;
  int pos, val, left, right;

  NumArray(vector<int>& nums) {
  	tree_size = nums.size() - 1;
    for (int i = 0; i < nums.size(); ++i) {
      arr[i] = nums[i];
    }
		build(1, 0, tree_size);
  }

  void build(int index, int l, int r) {
  	if (l == r) {
  		tree[index] = arr[l];
  		return;
  	}
  	build(index << 1, l, (l + r) >> 1);
  	build((index << 1) + 1, ((l + r) >> 1) + 1, r);
  	tree[index] = (tree[index << 1] +  tree[(index << 1) + 1]);
  }
  /*****/
	void update_tree(int index, int l, int r) {
		if (l > pos || pos > r) return;
		if (l == r) {
			tree[index] = val;
			return;
		}
		update_tree(index << 1, l, (l + r) >> 1);
		update_tree((index << 1) + 1, ((l + r) >> 1) + 1, r);
		tree[index] = (tree[index << 1] + tree[(index << 1) + 1]);
	}
  
  void update(int index, int val) {
    this->pos = index;
    this->val = val;
		update_tree(1, 0, tree_size);
  }
  /****/
  int range_sum_query(int index, int l, int r) {
		if (left > r || right < l) return 0;
    if (l == r) {
			return tree[index];
		}
    if (left <= l && r <= right) return tree[index];
		int left_sum = range_sum_query(index << 1, l, (l + r) >> 1);
		int right_sum = range_sum_query((index << 1) + 1, ((l + r) >> 1) + 1, r);
		return (left_sum + right_sum);
  }

  int sumRange(int left, int right) {
    this->left = left;
    this->right = right;
		return range_sum_query(1, 0, tree_size);
  }
  /****/
};

int main(void) {
	NumArray numArray = new NumArray([1, 3, 5]);
	numArray.sumRange(0, 2); // return 1 + 3 + 5 = 9
	numArray.update(1, 2);   // nums = [1, 2, 5]
	numArray.sumRange(0, 2); // return 1 + 2 + 5 = 8
	return 0;
}