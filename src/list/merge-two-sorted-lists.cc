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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode head(-1);
        ListNode* cur = &head;

        while (list1 && list2) {
            if (list1->val < list2->val) {
                ListNode* next = list1->next;

                cur->next = list1;
                cur = cur->next;
                cur->next = nullptr;

                list1 = next;
            } else {
                ListNode* next = list2->next;

                cur->next = list2;
                cur = cur->next;
                cur->next = nullptr;

                list2 = next;
            }
        }

        if (list1) {
            while (list1) {
                ListNode* next = list1->next;

                cur->next = list1;
                cur = cur->next;
                cur->next = nullptr;

                list1 = next;
            }
        }
        else if (list2) {
            while (list2) {
                ListNode* next = list2->next;

                cur->next = list2;
                cur = cur->next;
                cur->next = nullptr;

                list2 = next;
            }
        }

        return head.next;
    }
};