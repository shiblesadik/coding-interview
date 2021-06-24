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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (left == right) return head;
        ListNode* first(nullptr);
        ListNode* first_pre(nullptr);
        ListNode* last(nullptr);
        ListNode* last_post(nullptr);
        ListNode* pre(nullptr);
        ListNode* temp_next(nullptr);
        ListNode* temp_root(nullptr);
        ListNode* root = new ListNode(0, head);
        int pos = 0;
        bool work = false;
        while (root != nullptr) {
            if (pos == (left - 1)) {
                first_pre = root;
            }
            if (pos == right) {
                // cout << first_pre << " " << first_pre->next << " : " << first << " " << first->next << " : " << pre << " " << pre->next << " : "  << root << " " << root->next << endl;
                first_pre->next = root;
                first->next = root->next;
                root->next = pre;
                // cout << first_pre << " " << first_pre->next << " : " << first << " " << first->next << " : " << pre << " " << pre->next << " : "  << root << " " << root->next << endl;
                if (left == 1) return root;
                else return head;
                work = false;
                break;
            }
            if (work) {
                temp_next = root->next;
                temp_root = root;
                root->next = pre;
                root = temp_next;
                pre = temp_root;
            }
            if (pos == left) {
                first = root;
                pre = root;
                work = true;
                root = root->next;
            }
            ++pos;
            if (!work) root = root->next;
        }
        if (left == 1) head = first;
        return head;
    }
};
