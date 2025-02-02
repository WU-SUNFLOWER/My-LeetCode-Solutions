/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        std::unordered_set<ListNode*> addr_set;

        while (headA) {
            addr_set.insert(headA);
            headA = headA->next;
        }

        while (headB) {
            if (addr_set.count(headB) > 0) {
                return headB;
            }
            headB = headB->next;
        }

        return nullptr;

    }
};