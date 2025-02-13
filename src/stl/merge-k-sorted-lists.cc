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

struct ListNodeCompare {
    bool operator()(const ListNode* node1, const ListNode* node2) {
        return node1->val > node2->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        std::priority_queue<ListNode*, std::vector<ListNode*>, ListNodeCompare> q;
        for (ListNode* head : lists) {
            if (head) q.push(head);
        }

        ListNode new_head;
        ListNode* cur = &new_head;
        while (!q.empty()) {
            ListNode* next_node = q.top();
            q.pop();
            if (next_node->next) q.push(next_node->next);

            cur->next = next_node;
            next_node->next = nullptr;
            cur = cur->next;
        }

        return new_head.next;
    }
};