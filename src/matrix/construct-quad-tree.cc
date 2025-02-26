/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    Node* BuildNode(const vector<vector<int>>& grid, int start_i, int start_j, int size) {
        // 检查当前节点是否是叶子节点
        bool found_one = false;
        bool found_zero = false;
        for (int i = start_i; i < start_i + size; ++i) {
            for (int j = start_j; j < start_j + size; ++j) {
                if (grid[i][j] == 1) found_one = true;
                if (grid[i][j] == 0) found_zero = true;
                if (found_one && found_zero) goto after_nest_loop; 
            }
        }

after_nest_loop:
        // 如果当前节点是非叶子节点
        Node* node = new Node();
        if (found_one && found_zero) {
            node->isLeaf = false;
            node->val = 1;

            int split_size = size / 2;
            node->topLeft = BuildNode(grid, start_i, start_j, split_size);
            node->topRight = BuildNode(grid, start_i, start_j + split_size, split_size);
            node->bottomLeft = BuildNode(grid, start_i + split_size, start_j, split_size);
            node->bottomRight = BuildNode(grid, start_i + split_size, start_j + split_size, split_size);
        }
        // 如果当前节点是叶子节点
        else {
            node->isLeaf = true;
            node->val = found_one ? 1 : 0;
        }

        return node;
    }

    Node* construct(vector<vector<int>>& grid) {
        return BuildNode(grid, 0, 0, grid.size());
    }
};