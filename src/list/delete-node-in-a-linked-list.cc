class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* slow = node;
        ListNode* fast = node->next;
        while (fast->next != nullptr) {
            slow->val = fast->val;
            slow = slow->next;
            fast = fast->next;
        }
        slow->val = fast->val;
        slow->next = nullptr;
    }
};