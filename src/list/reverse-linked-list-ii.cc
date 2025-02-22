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
    void Reverse(ListNode* left, ListNode* right, ListNode** head, ListNode* prev, ListNode* next) {
        ListNode new_head;

        auto cur = left;
        while (true) {
            auto next = cur->next;
            {
                cur->next = new_head.next;
                new_head.next = cur;
            }
            if (cur == right) {
                break;
            }
            cur = next;
        }

        if (prev) {
            prev->next = right;
        } else {
            *head = right;
        }

        if (left) {
            left->next = next;
        }
    }

    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* left_node = nullptr;
        ListNode* right_node = nullptr;
        ListNode* last_node = nullptr;
        ListNode* next_node = nullptr;

        int tmp = 0;
        for (ListNode* cur = head, *last = nullptr; 
             cur != nullptr;) 
        {
            ++tmp;
            if (tmp == left) {
                left_node = cur;
                last_node = last;
            }
            if (tmp == right) {
                right_node = cur;
                next_node = cur->next;
                break;
            }
            last = cur;
            cur = cur->next;
        }

        // 翻转链表
        Reverse(left_node, right_node, &head, last_node, next_node);

        return head;
    }
};