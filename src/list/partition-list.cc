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
    ListNode* partition(ListNode* head, int x) {
        ListNode tmp_head_1;
        ListNode tmp_head_2;
        ListNode* tmp_cur_1 = &tmp_head_1;
        ListNode* tmp_cur_2 = &tmp_head_2;

        ListNode* cur = head;
        while (cur != nullptr) {
            if (cur->val < x) {
                tmp_cur_1->next = cur;
                cur = cur->next;
                tmp_cur_1 = tmp_cur_1->next;
                tmp_cur_1->next = nullptr;

            } else {
                tmp_cur_2->next = cur;
                cur = cur->next;
                tmp_cur_2 = tmp_cur_2->next;
                tmp_cur_2->next = nullptr;
            }
        }

        // 重新组装链表
        ListNode ans_head;
        ListNode* ans_cur = &ans_head;

        tmp_cur_1 = tmp_head_1.next;
        tmp_cur_2 = tmp_head_2.next;

        while (tmp_cur_1 != nullptr) {
            ListNode* next = tmp_cur_1->next;

            ans_cur->next = tmp_cur_1;
            ans_cur = ans_cur->next;
            ans_cur->next = nullptr;

            tmp_cur_1 = next;
        }

        while (tmp_cur_2 != nullptr) {
            ListNode* next = tmp_cur_2->next;

            ans_cur->next = tmp_cur_2;
            ans_cur = ans_cur->next;
            ans_cur->next = nullptr;

            tmp_cur_2 = next;
        }

        return ans_head.next;
    }
};