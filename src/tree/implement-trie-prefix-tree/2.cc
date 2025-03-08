class TrieNode {
public:
    bool is_word_;
    std::vector<TrieNode*> vec_;

    TrieNode() : is_word_(false), vec_(26, nullptr) {}
};

class Trie {
private:
    TrieNode* root;

public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* cur_node = root;
        for (char ch : word) {
            if (cur_node->vec_[ch - 'a'] == nullptr) {
                cur_node->vec_[ch - 'a'] = new TrieNode();
            }
            cur_node = cur_node->vec_[ch - 'a'];
        }
        cur_node->is_word_ = true;
    }
    
    bool search(string word) {
        TrieNode* cur_node = root;
        for (char ch : word) {
            cur_node = cur_node->vec_[ch - 'a'];
            if (cur_node == nullptr) {
                return false;
            }
        }
        return cur_node->is_word_;
    }
    
    bool startsWith(string prefix) {
        TrieNode* cur_node = root;
        for (char ch : prefix) {
            cur_node = cur_node->vec_[ch - 'a'];
            if (cur_node == nullptr) {
                return false;
            }
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */