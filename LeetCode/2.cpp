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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* first_node = l1;
        ListNode* last_node = l2;
        int first_length = 0;
        int last_length = 0;
        while (l1 != nullptr) {
            ++first_length;
            l1 = l1->next;
        }
        while (l2 != nullptr) {
            ++last_length;
            l2 = l2->next;
        }
        l1 = first_node;
        l2 = last_node;
        ListNode* final_node;
        ListNode* ite_node;
        if (first_length >= last_length) final_node = first_node;
        else final_node = last_node;
        ite_node = final_node;
        int val1 = 0, val2 = 0;
        int carry = 0;
        while (ite_node != nullptr) {
            val1 = val2 = 0;
            if (l1 != nullptr) val1 = l1->val;
            if (l2 != nullptr) val2 = l2->val;
            if ((val1 + val2 + carry) > 9) {
                ite_node->val = (val1 + val2 + carry) % 10;
                carry = 1;
            } else {
                ite_node->val = (val1 + val2 + carry);
                carry = 0;
            }
            if (ite_node->next == nullptr) break;
            ite_node = ite_node->next;
            if (l1 != nullptr) l1 = l1->next;
            if (l2 != nullptr) l2 = l2->next;
        }
        if (carry > 0) {
            ite_node->next = new ListNode(1, nullptr);
        }
        return final_node;
    }
};
