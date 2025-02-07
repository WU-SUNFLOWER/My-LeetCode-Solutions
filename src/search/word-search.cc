class Solution {
private:
    bool visited_[10][10] = { 0 };

public:
    void ClearVisitedMatrix() {
        memset(visited_, 0, sizeof(visited_));
    }

    bool DFS(const vector<vector<char>>& board, int i, int j, const string& word, int next_idx) {
        if (next_idx == word.size()) {
            return true;
        }
        
        visited_[i][j] = true;

        char next_ch = word[next_idx];
        int height = board.size();
        int width = board[0].size();

        if (0 <= i - 1 && !visited_[i - 1][j] && board[i - 1][j] == next_ch) {
            if (DFS(board, i - 1, j, word, next_idx + 1)) {
                return true;
            }
            visited_[i - 1][j] = false;
        }
        if (0 <= j - 1 && !visited_[i][j - 1] && board[i][j - 1] == next_ch) {
            if (DFS(board, i, j - 1, word, next_idx + 1)) {
                return true;
            }
            visited_[i][j - 1] = false;
        }
        if (i + 1 < height && !visited_[i + 1][j] && board[i + 1][j] == next_ch) {
            if (DFS(board, i + 1, j, word, next_idx + 1)) {
                return true;
            }
            visited_[i + 1][j] = false;
        }
        if (j + 1 < width && !visited_[i][j + 1] && board[i][j + 1] == next_ch) {
            if (DFS(board, i, j + 1, word, next_idx + 1)) {
                return true;
            }
            visited_[i][j + 1] = false;
        }
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        char first_char = word[0];
        int height = board.size();
        int width = board[0].size();

        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j) {
                if (board[i][j] == first_char && DFS(board, i, j, word, 1)) {
                    return true;
                }
                ClearVisitedMatrix();
            }
        }

        return false;
    }
};