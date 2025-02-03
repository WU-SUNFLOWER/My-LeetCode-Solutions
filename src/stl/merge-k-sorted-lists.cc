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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto comparer = [](ListNode* a, ListNode* b) {
            return a->val > b->val;
        };
        std::priority_queue<ListNode*, std::vector<ListNode*>, decltype(comparer)> q;

        for (ListNode* list : lists) {
            if (list) {
                q.push(list);
            }
        }

        ListNode new_head;
        ListNode* new_list_ptr = &new_head;
        while (!q.empty()) {
            ListNode* node = q.top();
            q.pop();
            
            if (node->next) {
                q.push(node->next);
            }
            
            new_list_ptr->next = node;
            node->next = nullptr;
            new_list_ptr = node;
        }

        return new_head.next;
    }
};