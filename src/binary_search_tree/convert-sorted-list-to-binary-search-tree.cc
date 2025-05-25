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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

#define IS_NULL(x) (x == nullptr)

class Solution {
public:
    void PrintError(const char* msg) {
        std::cerr << msg << std::endl;
        exit(-1);
    }

    ListNode* SplitList(ListNode* head, ListNode*& list1, ListNode*& list2) {
        if (IS_NULL(head)) {
            PrintError("illegal list!");
        }
        if (IS_NULL(head->next)) {
            list1 = list2 = nullptr;
            return head;
        }

        ListNode* slow = head;
        ListNode* fast = head->next->next;

        while (!IS_NULL(fast) && !IS_NULL(fast->next)) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* middle = slow->next;

        // split the original list.
        list1 = head;
        list2 = middle->next;
        slow->next = nullptr;
        middle->next = nullptr;

        return middle;
    }

    TreeNode* BuildNewTree(ListNode* head) {
        if (IS_NULL(head)) {
            return nullptr;
        }
        
        ListNode* list1 = nullptr;
        ListNode* list2 = nullptr;
        ListNode* mid = SplitList(head, list1, list2);
        
        TreeNode* node = new TreeNode(mid->val);
        node->left = BuildNewTree(list1);
        node->right = BuildNewTree(list2);

        return node;
    }

    TreeNode* sortedListToBST(ListNode* head) {
        if (IS_NULL(head)) {
            return nullptr;
        }
        if (IS_NULL(head->next)) {
            return new TreeNode(head->val);
        }

        return BuildNewTree(head);
    }
};