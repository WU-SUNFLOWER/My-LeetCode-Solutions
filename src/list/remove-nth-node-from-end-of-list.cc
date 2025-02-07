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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        std::stack<ListNode*> stack;
        ListNode new_head;
        new_head.next = head;
        ListNode* cur = &new_head;
        while (cur) {
            stack.push(cur);
            cur = cur->next;
        }
        ListNode* target;
        ListNode* pre;
        while (n-- > 0) {
            target = stack.top();
            stack.pop();
        }

        pre = stack.top();
        pre->next = target->next;
        return new_head.next;
    }
};