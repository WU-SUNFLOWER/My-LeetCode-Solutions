const std::vector<std::pair<int, int>> kDirections = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };

class Solution {
private:
    bool visited_[301][301] = { false };
public:
    // Is val in [low, high) ?
    bool InRange(int val, int low, int high) {
        return low <= val && val < high;
    }

    void BFS(vector<vector<char>>& grid, int i, int j) {
        int height = grid.size();
        int width = grid[0].size();

        std::queue<std::pair<int, int>> q;
        q.push({ i, j });
        visited_[i][j] = true;
        
        while (!q.empty()) {
            auto [cur_i, cur_j] = q.front();
            q.pop();

            for (auto [d_i, d_j] : kDirections) {
                int next_i = cur_i + d_i;
                int next_j = cur_j + d_j;
                if (InRange(next_i, 0, height) 
                    && InRange(next_j, 0, width) 
                    && grid[next_i][next_j] == '1'
                    && !visited_[next_i][next_j]) 
                {
                    visited_[next_i][next_j] = true;
                    q.push({ next_i, next_j });
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        int height = grid.size();
        int width = grid[0].size();

        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j) {
                if (!visited_[i][j] && grid[i][j] == '1') {
                    ++ans;
                    BFS(grid, i, j);
                }
            }
        }

        return ans;
    }
};