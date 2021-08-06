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
  vector<vector<int>> v;

  void dfs(TreeNode* root, int level) {
    if (root == nullptr) return;
    if (v.size() < level) {
      vector<int> vv;
      this->v.push_back(vv);
    }
    this->v[level - 1].push_back(root->val);
    dfs(root->left, level + 1);
    dfs(root->right, level + 1);
  }

  vector<vector<int>> levelOrder(TreeNode* root) {
    dfs(root, 1);
    return v;
  }
};
