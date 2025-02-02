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
    ListNode* oddEvenList(ListNode* head) {
        ListNode list_head_1(-1), list_head_2(-1);
        ListNode* list_ptr_1 = &list_head_1;
        ListNode* list_ptr_2 = &list_head_2;

        bool is_odd = true;
        ListNode* cur = head;
        while (cur != nullptr) {
            ListNode* next = cur->next;
            // remove current node from original list,
            // and add it to the target list.
            {
                if (is_odd) {
                    list_ptr_1->next = cur;
                    cur->next = nullptr;
                    list_ptr_1 = list_ptr_1->next;
                } else {
                    list_ptr_2->next = cur;
                    cur->next = nullptr;
                    list_ptr_2 = list_ptr_2->next;
                }
                is_odd = !is_odd;
            }
            cur = next;
        }

        // merge list_2 with list_1
        list_ptr_1->next = list_head_2.next;

        return list_head_1.next;
    }
};