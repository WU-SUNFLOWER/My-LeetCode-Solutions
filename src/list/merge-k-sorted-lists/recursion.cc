class Solution {
  public:
    ListNode* MergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode new_list;
        ListNode* new_list_tail = &new_list;
        while (list1 && list2) {
            if (list1->val < list2->val) {
                new_list_tail->next = list1;
                list1 = list1->next;
            } else {
                new_list_tail->next = list2;
                list2 = list2->next;
            }
            new_list_tail = new_list_tail->next;
        }
        while (list1) {
            new_list_tail->next = list1;
            list1 = list1->next;
            new_list_tail = new_list_tail->next;
        }
        while (list2) {
            new_list_tail->next = list2;
            list2 = list2->next;
            new_list_tail = new_list_tail->next;
        }
        return new_list.next;
    }

    ListNode* MergeLists(const std::vector<ListNode*>& lists, int i, int j) {
        int m = j - i;
        if (m == 0) {
            return nullptr;
        }
        if (m == 1) {
            return lists[i];
        }

        ListNode* left = MergeLists(lists, i, i + m / 2);
        ListNode* right = MergeLists(lists, i + m / 2, j);
        return MergeTwoLists(left, right);
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return MergeLists(lists, 0, lists.size());
    }
};