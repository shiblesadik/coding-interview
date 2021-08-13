/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
  int arr[20004] = {0};
  int size = 0;
  
  TreeNode* build(int l, int r) {
    if (l > r) return nullptr;
    int mid = (l + r) >> 1;
    TreeNode* node = new TreeNode(arr[mid]);
    node->right = build(mid + 1, r);
    node->left = build(l, mid - 1);
    return node;
  }
  
  TreeNode* sortedListToBST(ListNode* head) {
    while (head != nullptr) {
      arr[size++] = head->val;
      head = head->next;
    }
    
    return build( 0, size - 1);
  }
};