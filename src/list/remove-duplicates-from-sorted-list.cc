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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* first = head;
        ListNode* second = nullptr;

        while (first != nullptr && first->next != nullptr) {
            second = first->next;

            if (first->val != second->val) {
                first = second;
                continue;
            }

            first->next = second->next;

            // release the dup node
            second->next = nullptr;
            delete second;
        }

        return head;
    }
};