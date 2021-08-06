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
  ListNode* rotateRight(ListNode* head, int k) {
    int len = 0;
    ListNode* root = head;
    while (root != nullptr) {
      ++len;
      root = root->next;
    }
    if (len == 0 || k == 0) return head;
    k %= len;
    if (k == 0) return head;
    root = head;
    int p = 0;
    ListNode *lastNode, *preHead;
    while (root != nullptr) {
      ++p;
      if (len - p == k) {
        preHead = root;
      }
      if (p == len) {
        lastNode = root;
      }
      root = root->next;
    }
    lastNode->next = head;
    head = preHead->next;
    preHead->next = nullptr;
    return head;
  }
};
