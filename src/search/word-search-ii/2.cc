class Solution {
private:
    int height_;
    int width_;

    std::vector<std::string> ans_;
    std::unordered_set<std::string> word_set_;

    std::vector<std::pair<int, int>> dir_ = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };

public:
    void Search(const std::vector<std::vector<char>>& board, std::vector<std::vector<bool>>& vis, int i, int j, std::string& path) {
        vis[i][j] = true;
        path.push_back(board[i][j]);
        
        if (word_set_.contains(path)) {
            ans_.emplace_back(path);
            word_set_.erase(path);
        }

        if (path.size() >= 10) {
            path.pop_back();
            vis[i][j] = false;
            return;
        }

        for (auto [di, dj] : dir_) {
            int new_i = i + di;
            int new_j = j + dj;
            if (0 <= new_i && new_i < height_ && 0 <= new_j && new_j < width_ && !vis[new_i][new_j]) {
                Search(board, vis, new_i, new_j, path);
            }
        }

        path.pop_back();
        vis[i][j] = false;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        height_ = board.size();
        width_ = board[0].size();

        word_set_.insert(words.begin(), words.end());

        std::vector<std::vector<bool>> vis(height_, std::vector<bool>(width_, false));
        std::string path;

        for (int i = 0; i < height_; ++i) {
            for (int j = 0; j < width_; ++j) {
                if (word_set_.empty()) goto ret;
                Search(board, vis, i, j, path);
            }
        }

ret:
        return ans_;
    }
};