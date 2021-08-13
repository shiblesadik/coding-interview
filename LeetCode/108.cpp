/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
  vector<int> v;
  
  TreeNode* build(int l, int r) {
    if (l > r) return nullptr;
    int mid = (l + r) >> 1;
    TreeNode* node = new TreeNode(v[mid]);
    node->right = build(mid + 1, r);
    node->left = build(l, mid - 1);
    return node;
  }
  
  TreeNode* sortedArrayToBST(vector<int>& nums) {
    v = nums;
    
    return build(0, nums.size() - 1);
  }
};