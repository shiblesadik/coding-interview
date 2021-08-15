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
  bool isSymmetric(TreeNode* root) {
    TreeNode* leftNode;
    TreeNode* rightNode;
    queue<TreeNode*> left;
    queue<TreeNode*> right;
    left.push(root->left);
    right.push(root->right);
    bool symmetric = true;
    while (!left.empty() && !right.empty()) {
      leftNode = left.front();
      rightNode = right.front();
      left.pop(), right.pop();
      if (leftNode == nullptr && rightNode == nullptr) continue;
      if (leftNode == nullptr && rightNode != nullptr || 
          leftNode != nullptr && rightNode == nullptr) {
        symmetric = false;
        break;
      }
      if (leftNode->val != rightNode-> val) {
        symmetric = false;
        break;
      }
      left.push(leftNode->left);
      left.push(leftNode->right);
      right.push(rightNode->right);
      right.push(rightNode->left);
    }
    if (!left.empty() || !right.empty()) symmetric = false;
    return symmetric;
  }
};