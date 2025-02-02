class TrieNode {
 private:
    TrieNode* children_[26];
    bool is_tail_of_word_;

 public:
    TrieNode() : is_tail_of_word_(false) {
        for (int i = 0; i < sizeof(children_) / sizeof(children_[0]); ++i) {
            children_[i] = nullptr;
        }
    }

    TrieNode* GetChild(int idx) {
        return children_[idx];
    }

    void SetChild(int idx, TrieNode* child) {
        children_[idx] = child;
    }

    void SetTailOfWord(bool flag) {
        is_tail_of_word_ = flag;
    }

    bool IsTailOfWord() {
        return is_tail_of_word_;
    }
};

#define CHAR_TO_IDX(ch) (ch - 'a')

class Trie {
 private:
    TrieNode* root_;
 public:
    Trie() : root_(new TrieNode()) {}
    
    void insert(std::string word) {
        TrieNode* current_node = root_;
        for (int i = 0; i < word.size(); ++i) {
            char ch = word[i];
            TrieNode* next_node = current_node->GetChild(CHAR_TO_IDX(ch));
            if (next_node == nullptr) {
                next_node = new TrieNode();
                current_node->SetChild(CHAR_TO_IDX(ch), next_node);
            }
            current_node = next_node;
        }
        current_node->SetTailOfWord(true);
    }
    
    bool search(std::string word) {
        TrieNode* current_node = root_;
        for (int i = 0; i < word.size(); ++i) {
            char ch = word[i];
            TrieNode* next_node = current_node->GetChild(CHAR_TO_IDX(ch));
            if (next_node == nullptr) {
                return false;
            }
            current_node = next_node;
        }

        return current_node->IsTailOfWord();
    }
    
    bool startsWith(std::string prefix) {
        TrieNode* current_node = root_;
        for (int i = 0; i < prefix.size(); ++i) {
            char ch = prefix[i];
            TrieNode* next_node = current_node->GetChild(CHAR_TO_IDX(ch));
            if (next_node == nullptr) {
                return false;
            }
            current_node = next_node;
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