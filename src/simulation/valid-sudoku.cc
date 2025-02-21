class Solution {
public:
    bool CheckSmallMatrix(const vector<vector<char>>& board, int start_i, int start_j) {
        std::unordered_set<char> recorder;
        for (int i = start_i; i < start_i + 3; ++i) {
            for (int j = start_j; j < start_j + 3; ++j) {
                char ch = board[i][j];
                if (!('1' <= ch && ch <= '9')) {
                    continue;
                }
                if (recorder.contains(ch)) {
                    return false;
                }
                recorder.insert(ch);
            }
        }
        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        int height = board.size();
        int width = board[0].size();

        // 1.数字 1-9 在每一行只能出现一次。
        std::unordered_set<char> recorder;
        for (int row = 0; row < height; ++row) {
            recorder.clear();
            for (int col = 0; col < width; ++col) {
                char ch = board[row][col];
                if (!('1' <= ch && ch <= '9')) {
                    continue;
                }
                if (recorder.contains(ch)) {
                    return false;
                }
                recorder.insert(ch);
            }
        }

        // 2. 数字 1-9 在每一列只能出现一次。
        for (int col = 0; col < width; ++col) {
            recorder.clear();
            for (int row = 0; row < height; ++row) {
                char ch = board[row][col];
                if (!('1' <= ch && ch <= '9')) {
                    continue;
                }
                if (recorder.contains(ch)) {
                    return false;
                }
                recorder.insert(ch);
            }
        }

        for (int row = 0; row < height; row += 3) {
            for (int col = 0; col < height; col += 3) {
                if (!CheckSmallMatrix(board, row, col)) {
                    return false;
                }
            }
        }

        return true;
    }
};