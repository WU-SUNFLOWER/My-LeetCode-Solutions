class Solution {
private:
    //std::unordered_set<std::pair<int, int>> dead_areas;
    bool dead_areas[200][200] = { false };

public:
    bool Expand(vector<vector<char>>& board, int i, int j, int height, int width, std::vector<std::pair<int, int>>& outs) {
        std::queue<std::pair<int, int>> q;
        std::set<std::pair<int, int>> visited;

        q.push({ i, j });

        while (!q.empty()) {
            auto [i, j] = q.front();
            q.pop();
            visited.insert({ i, j });

            if (i == 0 || i == height - 1 || j == 0 || j == width - 1 || dead_areas[i][j]) {
                return false;
            }

            outs.push_back({ i, j });

            if (board[i - 1][j] == 'O' && !visited.contains({ i - 1, j })) q.push({ i - 1, j });
            if (board[i + 1][j] == 'O' && !visited.contains({ i + 1, j })) q.push({ i + 1, j });
            if (board[i][j - 1] == 'O' && !visited.contains({ i, j - 1 })) q.push({ i, j - 1 });
            if (board[i][j + 1] == 'O' && !visited.contains({ i, j + 1 })) q.push({ i, j + 1 });

        }

        return true;
    }

    void Markup(vector<vector<char>>& board, std::vector<std::pair<int, int>>& outs) {
        for (auto [i, j] : outs) {
            board[i][j] = 'X';
        }
    }

    void UpdateDeadArea(std::vector<std::pair<int, int>>& outs) {
        for (auto [i, j] : outs) {
            dead_areas[i][j] = true;
        }
    }

    void solve(vector<vector<char>>& board) {
        int height = board.size();
        if (height <= 0) return;
        int width = board[0].size();

        std::vector<std::pair<int, int>> outs;

        for (int i = 1; i < height - 1; ++i) {
            for (int j = 1; j < width - 1; ++j) {
                if (board[i][j] == 'O' && !dead_areas[i][j]) {
                    if (Expand(board, i, j, height, width, outs)) {
                        Markup(board, outs);
                    } else {
                        UpdateDeadArea(outs);
                    }
                    outs.clear();
                }
            }
        }
    }
};