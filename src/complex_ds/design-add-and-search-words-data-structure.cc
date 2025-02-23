#define GET_IDX(ch) (ch - 'a')

class TrieNode {
 public:
    TrieNode* children_[26] { nullptr };
    bool is_word_ { false };
};

class WordDictionary {
 private:
    TrieNode* root_;

 public:

    WordDictionary() {
        root_ = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* cur;
        TrieNode* parent = root_;
        for (int i = 0; i < word.size(); ++i) {
            cur = parent->children_[GET_IDX(word[i])];
            if (cur == nullptr) {
                cur = new TrieNode();
                parent->children_[GET_IDX(word[i])] = cur;
            }
            parent = cur;
        }
        cur->is_word_ = true;
    }
    
    bool SearchInTrieTree(TrieNode* parent, const std::string& word, int word_idx) {
        if (word[word_idx] != '.') {
            TrieNode* cur = parent->children_[GET_IDX(word[word_idx])];
            if (cur == nullptr) {
                return false;
            } 
            else if (word_idx == word.size() - 1) {
                return cur->is_word_;
            }
            else {
                return SearchInTrieTree(cur, word, word_idx + 1);
            }
        } else {
            if (word_idx == word.size() - 1) {
                for (int i = 0; i < 26; ++i) {
                    if (parent->children_[i] && parent->children_[i]->is_word_) {
                        return true;
                    }
                }
            } else {
                for (int i = 0; i < 26; ++i) {
                    if (parent->children_[i] && SearchInTrieTree(parent->children_[i], word, word_idx + 1)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }

    bool search(string word) {
        return SearchInTrieTree(root_, word, 0);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */