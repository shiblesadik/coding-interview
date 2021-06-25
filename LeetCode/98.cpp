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
    bool isValidBST(TreeNode* root) {
        if (root == nullptr) return true;
        return dfs(root).first;
    }

    pair<bool, pair<int, int>> dfs(TreeNode* root) {
        pair<bool, pair<int, int>> left = {true, {root->val, root->val}}, right = {true, {root->val, root->val}};
        if (root->left != nullptr) {
            if (root->val > root->left->val) {
                left = dfs(root->left);
                if (left.first == false) return {false, {0, 0}};
                if (left.second.second >= root->val) return {false, {0, 0}};
                if (left.second.first >= root->val) return {false, {0, 0}};
            } else return {false, {0, 0}};
        }
        if (root->right != nullptr) {
            if (root->val < root->right->val) {
                right = dfs(root->right);
                if (right.first == false) return {false, {0, 0}};
                if (right.second.first <= root->val) return {false, {0, 0}};
                if (right.second.second <= root->val) return {false, {0, 0}};
            } else return {false, {0, 0}};
        }
        return {left.first & right.first, {min(root->val, min(left.second.first, right.second.first)), max(root->val, max(left.second.second, right.second.second))}};
    }
};
