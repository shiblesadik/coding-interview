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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> vec;
        if (root == nullptr) return vec;
        if (root->left != nullptr) {
            vector<vector<int>> left = pathSum(root->left, targetSum - root->val);
            if (left.size() > 0) {
                for (int i = 0; i < left.size(); ++i) {
                    left[i].insert(left[i].begin(), root->val);
                    vec.push_back(left[i]);
                }
            }
        }
        if (root->right != nullptr) {
            vector<vector<int>> right = pathSum(root->right, targetSum - root->val);
            if (right.size() > 0) {
                for (int i = 0; i < right.size(); ++i) {
                    right[i].insert(right[i].begin(), root->val);
                    vec.push_back(right[i]);
                }
            }
        }
        if (root->left == nullptr && root->right == nullptr) {
            if (targetSum - root->val == 0) {
                vector<vector<int>> it = {{root->val}};
                return {{root->val}};
            } else {
                return {};
            }
        }
        return vec;
    }
};
