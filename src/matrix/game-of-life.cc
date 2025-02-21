class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        std::vector<std::pair<int, int>> to_die_pos;
        std::vector<std::pair<int, int>> to_relive_pos;

        int height = board.size();
        if (height <= 0)
            return;
        int width = board[0].size();

        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j) {
                // 统计周围的活细胞数目
                int cnt = 0;
                if (0 < i) {
                    cnt += board[i - 1][j];
                    if (0 < j)
                        cnt += board[i - 1][j - 1];
                    if (j < width - 1)
                        cnt += board[i - 1][j + 1];
                }
                if (0 < j) {
                    cnt += board[i][j - 1];
                    if (i < height - 1)
                        cnt += board[i + 1][j - 1];
                }
                if (i < height - 1) {
                    cnt += board[i + 1][j];
                    if (j < width - 1)
                        cnt += board[i + 1][j + 1];
                }
                if (j < width - 1) {
                    cnt += board[i][j + 1];
                }

                // 如果活细胞周围八个位置的活细胞数少于两个，则该位置活细胞死亡；
                // 如果活细胞周围八个位置有两个或三个活细胞，则该位置活细胞仍然存活；
                // 如果活细胞周围八个位置有超过三个活细胞，则该位置活细胞死亡；
                if (board[i][j] && (cnt < 2 || cnt > 3)) {
                    to_die_pos.push_back({ i, j });
                }
                // 如果死细胞周围正好有三个活细胞，则该位置死细胞复活；
                else if (cnt == 3) {
                    to_relive_pos.push_back({ i, j });
                }
            }
        }

        for (auto [i, j] : to_die_pos) {
            board[i][j] = 0;
        }

        for (auto [i, j] : to_relive_pos) {
            board[i][j] = 1;
        }
    }
};