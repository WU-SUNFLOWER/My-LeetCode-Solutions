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
    ListNode* DeleteNode(ListNode* target, ListNode* prev) {
        if (prev != nullptr) {
            prev->next = target->next;
        }
        ListNode* ret = target->next;
        delete target;
        return ret;
    }

    ListNode* deleteDuplicates(ListNode* head) {
        ListNode tmp_head(-1000, head);
        ListNode* prev = &tmp_head;
        ListNode* slow = prev->next;

        while (slow != nullptr) {
            ListNode* fast = slow->next;
            if (fast && fast->val == slow->val) {
                while (fast && fast->val == slow->val) {
                    fast = DeleteNode(fast, slow);
                }
                slow = DeleteNode(slow, prev);
            } else {
                prev = slow;
                slow = slow->next;
            }
        }

        return tmp_head.next;
    }
};