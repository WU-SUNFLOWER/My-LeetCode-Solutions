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
    ListNode* swapPairs(ListNode* head) {
        ListNode new_head(-1);
        ListNode* new_list_cur = &new_head;

        ListNode* cur = head;
        while (cur != nullptr) {
            ListNode* first = cur;
            ListNode* second = cur->next;

            if (second) {
                cur = second->next;
            } else {
                new_list_cur->next = first;
                first->next = nullptr;
                break;
            }

            new_list_cur->next = second;
            second->next = first;
            first->next = nullptr;

            new_list_cur = first;
        }

        return new_head.next;
    }
};