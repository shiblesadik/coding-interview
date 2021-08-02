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
  ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode* mergedList = new ListNode();
    ListNode* l1_head = l1;
    ListNode* l2_head = l2;
    ListNode* head = mergedList;
    if (l1_head == nullptr && l2_head == nullptr) return nullptr;

    while (l1_head != nullptr || l2_head != nullptr) {
      if (l1_head == nullptr) {
        if (l2_head == nullptr) {
          break;
        } else {
          mergedList->val = l2_head->val;
          l2_head = l2_head->next;
        }
      } else if (l2_head == nullptr) {
        if (l1_head == nullptr) {
          break;
        } else {
          mergedList->val = l1_head->val;
          l1_head = l1_head->next;
        }
      } else if (l1_head->val <= l2_head->val) {
        mergedList->val = l1_head->val;
        l1_head = l1_head->next;
      } else if (l2_head->val <= l1_head->val) {
        mergedList->val = l2_head->val;
        l2_head = l2_head->next;
      } else {
        break;
      }
      mergedList->next = nullptr;
      if (l1_head != nullptr || l2_head != nullptr) {
        mergedList->next = new ListNode();
        mergedList = mergedList->next;
      }
    }
    mergedList = nullptr;
    return head;
  }
};
