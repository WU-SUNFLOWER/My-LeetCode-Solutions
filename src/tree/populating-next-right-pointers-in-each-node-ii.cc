/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if (!root) {
            return nullptr;
        }

        std::queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            int layer_size = q.size();

            // 将第一个元素置为last
            Node* last = nullptr;
            if (layer_size-- > 0) {
                last = q.front();
                q.pop();

                if (last->left) q.push(last->left);
                if (last->right) q.push(last->right);
            }

            while (layer_size-- > 0) {
                Node* cur = q.front();
                q.pop();
                last->next = cur;
                last = cur;

                if (last->left) q.push(last->left);
                if (last->right) q.push(last->right);
            }

            // 将当前层最后一个元素的next指针置为null
            last->next = nullptr;
        }

        return root;
    }
};