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
    bool isPalindrome(ListNode* head) {
        // special situations
        if (head == nullptr) {
            return false;
        }
        if (head->next == nullptr) {
            return true;
        }

        ListNode* slow = head;
        ListNode* fast = head->next->next;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* ptr1 = head;
        ListNode* ptr2 = reverseList(slow->next);
        slow->next = nullptr;
        while (ptr1 && ptr2) {
            if (ptr1->val != ptr2->val) {
                return false;
            }
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }

        return true;
    }

    ListNode* reverseList(ListNode* head) {
        ListNode tmp_head(-1);

        while (head != nullptr) {
            ListNode* next = head->next;

            ListNode* next_in_new_list = tmp_head.next;
            tmp_head.next = head;
            head->next = next_in_new_list;

            head = next;
        }

        return tmp_head.next;
    }
};