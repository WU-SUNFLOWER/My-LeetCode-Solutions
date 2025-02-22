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
    ListNode* rotateRight(ListNode* head, int k) {
        // 统计链表的总长度
        int total_len = 0;
        ListNode* cur = head;
        while (cur != nullptr) {
            ++total_len;
            cur = cur->next;
        }

        if (total_len == 0 || k == 0) {
            return head;
        }

        // 计算要剪切元素的个数
        int node_num = k % total_len;

        // 定位到倒数第node_num个元素的位置
        // 即正数第total_len-node_num+1个元素
        int tmp = 1;
        ListNode* last = head;
        cur = head->next;
        while (tmp < total_len - node_num) {
            ++tmp;
            last = cur;
            cur = cur->next;
        }

        // 将倒数第node_num个元素剪切到链表开头的位置
        ListNode new_head;

        if (cur == nullptr) {
            new_head.next = head;
        } else {
            new_head.next = cur;
            last->next = nullptr;
            while (cur && cur->next != nullptr) {
                cur = cur->next;
            }
            cur->next = head;            
        }

        return new_head.next;
    }
};