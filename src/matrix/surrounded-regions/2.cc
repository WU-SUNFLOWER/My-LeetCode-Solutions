class Solution {
private:
    std::vector<std::pair<int, int>> directions = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

public:
    void BFS(std::vector<std::vector<char>>& board, int i, int j, int height, int width) {
        std::queue<std::pair<int, int>> q;
        std::vector<std::vector<bool>> visited(height, std::vector<bool>(width, false));

        q.push({i, j});
        visited[i][j] = true;

        while (!q.empty()) {
            auto [i, j] = q.front();
            q.pop();

            assert(board[i][j] == 'O');

            board[i][j] = 'T';
            
            for (auto [delta_i, delta_j] : directions) {
                int new_i = i + delta_i;
                int new_j = j + delta_j;
                if (0 <= new_i &&
                    new_i < height && 
                    0 <= new_j &&
                    new_j < width && 
                    board[new_i][new_j] == 'O' &&
                    !visited[new_i][new_j])
                {
                    q.push({ new_i, new_j });
                    visited[new_i][new_j] = true;
                }
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        int height = board.size();
        int width = board[0].size();
        // 以矩阵的边界为起点，进行染色
        for (int i = 0; i < height; ++i) {
            if (board[i][0] == 'O') {
                BFS(board, i, 0, height, width);
            }
            if (board[i][width - 1] == 'O') {
                BFS(board, i, width - 1, height, width);
            }
        }
        for (int j = 0; j < width; ++j) {
            if (board[0][j] == 'O') {
                BFS(board, 0, j, height, width);
            }
            if (board[height - 1][j] == 'O') {
                BFS(board, height - 1, j, height, width);
            }
        }

        // 遍历整个矩阵
        // 将T染成O，将原先幸存的O染成X
        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j) {
                if (board[i][j] == 'T') {
                    board[i][j] = 'O';
                }
                else if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }
    }
};