/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        std::unordered_map<Node*, Node*> copy_map;

        Node new_head(0);
        Node* old_list_cur = head;
        Node* new_list_cur = &new_head;
        while (old_list_cur != nullptr) {
            Node* new_node = new Node(old_list_cur->val);
            new_node->next = nullptr;
            new_node->random = old_list_cur->random;

            new_list_cur->next = new_node;
            copy_map[old_list_cur] = new_node;

            new_list_cur = new_list_cur->next;
            old_list_cur = old_list_cur->next;
        }

        new_list_cur = new_head.next;
        while (new_list_cur != nullptr) {
            new_list_cur->random = copy_map[new_list_cur->random];
            new_list_cur = new_list_cur->next;
        }

        return new_head.next;
    }
};