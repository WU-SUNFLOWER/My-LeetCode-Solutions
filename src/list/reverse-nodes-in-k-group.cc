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
    ListNode* ReverseSingle(ListNode* node) {
        ListNode tmp_head;

        // 头插法
        while (node != nullptr) {
            ListNode* next_in_new_list = tmp_head.next;
            ListNode* next_in_old_list = node->next;
            // 将node节点插入到新链表的头部
            tmp_head.next = node;
            node->next = next_in_new_list;
            // 继续处理原链表的下一个节点
            node = next_in_old_list;
        }

        return tmp_head.next;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode tmp_head;
        ListNode* tail_in_new_list = &tmp_head;

        ListNode* start = head;

        int i = 0;
        while (head != nullptr) {
            ++i;
            if (i % k == 0) {
                ListNode* tail = head;
                // 先将head指针移动到下一个节点，以便后续循环可以继续
                head = head->next;
                {
                    // 从tail处断开链表，然后进行翻转
                    // 并将翻转后所得的链表插入到输出新链表的尾部
                    tail->next = nullptr;
                    tail_in_new_list->next = ReverseSingle(start);
                    // 更新tail_in_new_list指针，使其重新指向新链表的尾部
                    while (tail_in_new_list->next != nullptr) {
                        tail_in_new_list = tail_in_new_list->next;
                    }
                }
                // 最后别忘了更新start指针
                start = head;
            } else {
                head = head->next;
            }
        }

        // 如果节点总数不是 k 的整数倍，那么请将最后剩余的节点保持原有顺序。
        while (start != nullptr) {
            ListNode* next_in_old_list = start->next;
            {
                tail_in_new_list->next = start;
                start->next = nullptr;
                tail_in_new_list = tail_in_new_list->next;
            }
            start = next_in_old_list;
        }

        return tmp_head.next;
    }
};