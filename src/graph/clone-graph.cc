/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
private:
    std::unordered_set<Node*> visited_;
    std::unordered_map<Node*, Node*> copy_map_;
public:
    Node* TraverseAndCreateNewNode(Node* original_node) {
        visited_.insert(original_node);

        Node* new_node = new Node(original_node->val);
        copy_map_[original_node] = new_node;

        for (Node* sub_original_node : original_node->neighbors) {
            if (!visited_.contains(sub_original_node)) {
                TraverseAndCreateNewNode(sub_original_node);
            }
        }

        return new_node;
    }

    Node* TraverseAndSetChildren(Node* original_node) {
        visited_.insert(original_node);

        Node* new_node = copy_map_[original_node];

        for (Node* sub_original_node : original_node->neighbors) {
            new_node->neighbors.push_back(copy_map_[sub_original_node]);
            if (!visited_.contains(sub_original_node)) {
                TraverseAndSetChildren(sub_original_node);
            }
        }

        return new_node;
    }

    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;

        Node* new_root = TraverseAndCreateNewNode(node);
        visited_.clear();
        TraverseAndSetChildren(node);
        return new_root;
    }
};