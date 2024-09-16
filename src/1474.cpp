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
    ListNode* deleteNodes(ListNode* head, int m, int n) {
        ListNode* cur = head;
        ListNode* last = nullptr;
        while (cur != nullptr) {
            int count_ignore = 1;
            int count_remove = 0;
            while (count_ignore <= m && cur != nullptr) {
                last = cur;
                cur = cur->next;
                ++count_ignore;
            }
            while (count_remove < n && cur != nullptr) {
                last->next = cur->next;
                cur = last->next;
                ++count_remove;
            }
        }
        return head;
    }
};