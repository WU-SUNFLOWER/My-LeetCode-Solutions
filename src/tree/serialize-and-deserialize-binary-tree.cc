/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

typedef short NodeVal;
static const NodeVal kUndefinedNode = 0x7FFF;

class Codec {
private:

public:

    void SerializeEngine(TreeNode* node, std::string& binary) {
        if (!node) {
            binary.append(reinterpret_cast<const char*>(&kUndefinedNode), sizeof(NodeVal));
            return;
        }
        binary.append(reinterpret_cast<const char*>(&node->val), sizeof(NodeVal));
        SerializeEngine(node->left, binary);
        SerializeEngine(node->right, binary);
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        std::string binary;
        SerializeEngine(root, binary);
        return binary;
    }

    TreeNode* DeserializeEngine(const std::string& binary, size_t& offset) {
        NodeVal node_val = *(reinterpret_cast<const NodeVal*>(binary.c_str() + offset));
        offset += sizeof(NodeVal);
        if (node_val == kUndefinedNode) {
            return nullptr;
        }
        TreeNode* node = new TreeNode(node_val);
        node->left = DeserializeEngine(binary, offset);
        node->right = DeserializeEngine(binary, offset);
        return node;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        size_t offset = 0;
        return DeserializeEngine(data, offset);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));