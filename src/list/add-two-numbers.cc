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
    void ComputeValAndPre(int& val, int& pre) {
        int total_val = val;
        val %= 10;
        pre = total_val / 10;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int pre = 0, val = 0;
        ListNode new_list_head;
        ListNode* new_ptr = &new_list_head;

        while (l1 != nullptr && l2 != nullptr) {
            val = l1->val + l2->val + pre;
            ComputeValAndPre(val, pre);

            new_ptr->next = new ListNode(val);
            new_ptr = new_ptr->next;

            l1 = l1->next;
            l2 = l2->next;
        }

        while (l1) {
            val = l1->val + pre;
            ComputeValAndPre(val, pre);

            new_ptr->next = new ListNode(val);
            new_ptr = new_ptr->next;

            l1 = l1->next;
        }

        while (l2) {
            val = l2->val + pre;
            ComputeValAndPre(val, pre);

            new_ptr->next = new ListNode(val);
            new_ptr = new_ptr->next;

            l2 = l2->next;
        }

        if (pre) {
            new_ptr->next = new ListNode(pre);
            new_ptr = new_ptr->next;
        }

        return new_list_head.next;
    }
};