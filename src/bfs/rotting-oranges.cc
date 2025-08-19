#define IN_RANGE(x, l, r) ((l) <= (x) && (x) < (r))

const std::vector<std::pair<int, int>> kDirections = {
    {-1, 0}, {1, 0}, {0, -1}, {0, 1}
};

class Solution {
  public:
    enum State {
        kEmpty = 0,
        kFresh = 1,
        kRotten = 2
    };

    int orangesRotting(vector<vector<int>>& grid) {
        int height = grid.size();
        int width = grid[0].size();

        bool found_fresh = false;
        std::queue<std::pair<int, int>> q;
        // 先遍历一遍grid，初始化q
        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j) {
                if (grid[i][j] == kRotten) {
                    q.push({i, j});
                }
                found_fresh |= (grid[i][j] == kFresh);
            }
        }

        // 0 分钟时已经没有新鲜橘子了
        if (!found_fresh) {
            return 0;
        }

        int minutes = 0;
        while (!q.empty()) {
            int num = q.size();
            while (num-- > 0) {
                auto [i, j] = q.front();
                q.pop();
                for (auto [delta_i, delta_j] : kDirections) {
                    int near_i = i + delta_i;
                    int near_j = j + delta_j;
                    if (IN_RANGE(near_i, 0, height) && 
                            IN_RANGE(near_j, 0, width) &&
                            grid[near_i][near_j] == kFresh) {
                        grid[near_i][near_j] = kRotten;
                        q.push({near_i, near_j});
                    }
                }
            }
            ++minutes;
        }

        // 检查是否有橘子没腐烂
        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j) {
                if (grid[i][j] == kFresh) {
                    return -1;
                }
            }
        } 

        return minutes - 1;
    }
};