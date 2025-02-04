/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#define IS_NULL(n) (n == nullptr)

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (IS_NULL(head) || IS_NULL(head->next)) {
            return false;
        }

        ListNode* slow = head;
        ListNode* fast = head->next;

        while (!IS_NULL(fast) && !IS_NULL(fast->next)) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                return true;
            }
        }
        
        return false;
    }
};