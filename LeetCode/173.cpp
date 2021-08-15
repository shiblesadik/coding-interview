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
class BSTIterator {
public:
  int arr[100002] = {0};
  int totalSize = 0;
  int index = 0;

  void inOrder(TreeNode* root) {
    if (root == nullptr) return;
    inOrder(root->left);
    arr[totalSize++] = root->val;
    inOrder(root->right);      
  }
  
  BSTIterator(TreeNode* root) {
    inOrder(root);
  }

  int next() {
    return arr[index++];
  }

  bool hasNext() {
    if (index >= totalSize) return false;
    else return true;
  }
};

/**
* Your BSTIterator object will be instantiated and called as such:
* BSTIterator* obj = new BSTIterator(root);
* int param_1 = obj->next();
* bool param_2 = obj->hasNext();
*/