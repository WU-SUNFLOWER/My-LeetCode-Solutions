class Solution {
private:
    int ans_ = 0;

public:
    bool CanPut(const std::vector<std::vector<bool>>& board, int i, int j) {
        int n = board.size();

        int cur_i = i;
        int cur_j = j;
        while (0 <= cur_i && 0 <= cur_j) {
            if (board[cur_i][cur_j])
                return false;
            cur_i -= 1;
            cur_j -= 1;
        }

        cur_i = i;
        cur_j = j;
        while (0 <= cur_i && cur_j < n) {
            if (board[cur_i][cur_j])
                return false;
            cur_i -= 1;
            cur_j += 1;
        }

        return true;
    }

    void Search(std::vector<std::vector<bool>>& board, int idx, int last,
                std::vector<int>& locked_cols) {
        int n = board.size();
        int size = n * n;

        if (last == 0) {
            ++ans_;
            return;
        }

        if (idx >= size) {
            return;
        }

        int i = idx / n;
        int j = idx % n;
        // 当前格子放棋子
        if (!locked_cols[j] && CanPut(board, i, j)) {
            board[i][j] = 1;
            locked_cols[j] = 1;
            Search(board, (i + 1) * n, last - 1, locked_cols);
            board[i][j] = 0;
            locked_cols[j] = 0;
        }
        // 当前格子不放棋子
        Search(board, idx + 1, last, locked_cols);
    }

    int totalNQueens(int n) {
        // 0-当前格子没有摆放棋子
        // 1-当前格子已经摆放了棋子
        std::vector<std::vector<bool>> board(n, std::vector<bool>(n, 0));

        std::vector<int> locked_cols(n, 0);

        Search(board, 0, n, locked_cols);
        return ans_;
    }
};