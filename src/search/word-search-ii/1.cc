class Solution {
private:
    std::vector<std::pair<int, int>> directions_ = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

public:
    void ClearVisMatrix(std::vector<std::vector<bool>>& visited, int height, int width) {
        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j) {
                visited[i][j] = false;
            }
        }
    }

    bool Search(const std::vector<std::vector<char>>& board, 
                std::vector<std::vector<bool>>& vis, 
                int i, int j, 
                const std::string& word, 
                int word_idx) 
    {
        int height = board.size();
        int width = board[0].size();

        vis[i][j] = true;

        if (word_idx == word.size() - 1 && board[i][j] == word[word_idx]) {
            return true;
        }

        if (board[i][j] != word[word_idx]) {
            return false;
        }

        for (auto [di, dj] : directions_) {
            int new_i = i + di;
            int new_j = j + dj;
            if (0 <= new_i && new_i < height && 0 <= new_j && new_j < width && !vis[new_i][new_j]) {
                if (Search(board, vis, new_i, new_j, word, word_idx + 1)) return true;
                vis[new_i][new_j] = false;
            }
        }

        return false;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int height = board.size();
        int width = board[0].size();

        std::vector<std::vector<bool>> vis(height, std::vector<bool>(width, false));

        std::unordered_set<std::string> word_set(words.begin(), words.end());

        std::vector<std::string> ans;

        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j) {
                auto iter = word_set.begin();
                while (iter != word_set.end()) {
                    auto& word = *iter;
                    if (board[i][j] == word[0]) {
                        if (Search(board, vis, i, j, word, 0)) {
                            ans.emplace_back(word);
                            iter = word_set.erase(iter);
                        } else {
                            ++iter;
                        }
                        ClearVisMatrix(vis, height, width);
                    } else {
                        ++iter;
                    }
                }
            }
        }

        return ans;
    }
};