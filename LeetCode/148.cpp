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
class Solution {
public:
  ListNode* sortList(ListNode* head) {
    ListNode *left, *right;
    ListNode *root = head;
    int length = 0;
    while (root != nullptr) {
      ++length;
      root = root->next;
    }
    int power = 0, base = ceil(log2(length));
    while (power < base) {

    }
    return head;
  }
};
