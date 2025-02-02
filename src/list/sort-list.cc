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
    void printError(const char* msg) {
        std::cerr << msg << std::endl;
        exit(-1);
    }

    ListNode* splitList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next->next;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* mid = slow->next;
        slow->next = nullptr;
        return mid;
    }

    ListNode* mergeSort(ListNode* head) {
        // recursive exit
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        if (head->next->next == nullptr) {
            ListNode* first = head;
            ListNode* second = head->next;
            if (first->val < second->val) {
                return first;
            } else {
                second->next = first;
                first->next = nullptr;
                return second;
            }
        }

        // use merge sorting to process the left list and right list.
        ListNode* mid = splitList(head);
        ListNode* left = mergeSort(head);
        ListNode* right = mergeSort(mid);

        // merge left list with right list
        ListNode tmp_head(-1);
        ListNode* tail = &tmp_head;
        ListNode* pair_next = nullptr;
        while (left && right) {
            if (left->val < right->val) {
                pair_next = left->next;
                {
                    tail->next = left;
                    left->next = nullptr;    
                    tail = tail->next;                
                }
                left = pair_next;
            } else {
                pair_next = right->next;
                {
                    tail->next = right;
                    right->next = nullptr;
                    tail = tail->next;
                }
                right = pair_next;
            }
        }

        if (left && right) {
            printError("fail to merge left list and right list!");
        }

        // don't forget to insert the residual nodes to merged list!
        while (left != nullptr) {
            pair_next = left->next;
            {
                tail->next = left;
                left->next = nullptr;
                tail = tail->next;     
            }
            left = pair_next;
        }
        while (right != nullptr) {
            pair_next = right->next;
            {
                tail->next = right;
                right->next = nullptr;
                tail = tail->next;     
            }
            right = pair_next;
        }

        // return merged list
        return tmp_head.next;
    }

    ListNode* sortList(ListNode* head) {
        return mergeSort(head);
    }
};