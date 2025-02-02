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
    ListNode* reverseList(ListNode* head) {
        ListNode new_head(-1);

        ListNode* cur = head;
        while (cur != nullptr) {
            ListNode* new_head_succ = new_head.next;
            ListNode* next = cur->next;
            new_head.next = cur;
            cur->next = new_head_succ;
            cur = next;
        }

        return new_head.next;
    }
};