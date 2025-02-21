class Solution {
private:
    std::set<std::pair<int, int>> visited_;
    std::vector<int> outs_;

    int width_;
    int height_;

    enum class Direction {
        kLeft,
        kRight,
        kUp,
        kDown,
    };

public:
    std::pair<int, int> GoOneClock(std::vector<std::vector<int>>& matrix, int i, int j) {
        int min_i = i;
        int min_j = j;
        int max_i = height_ - min_i - 1;
        int max_j = width_ - min_j - 1;
        Direction dir = Direction::kRight;
        while (true) {
            if (!(min_i <= i && i <= max_i) || !(min_j <= j && j <= max_j) || visited_.contains({ i, j })) {
                return { min_i + 1, min_j + 1 };
            }
            visited_.insert({ i, j });
            outs_.push_back(matrix[i][j]);
            if (dir == Direction::kRight) {
                if (j >= max_j) {
                    i += 1;
                    dir = Direction::kDown;
                    continue;
                }
                j += 1;
            }
            else if (dir == Direction::kDown) {
                if (i >= max_i) {
                    j -= 1;
                    dir = Direction::kLeft;
                    continue;
                }
                i += 1;
            }
            else if (dir == Direction::kLeft) {
                if (j <= min_j) {
                    i -= 1;
                    dir = Direction::kUp;
                    continue;
                }
                j -= 1;
            }
            else if (dir == Direction::kUp) {
                if (i <= min_i) {
                    j += 1;
                    dir = Direction::kRight;
                    continue;
                }
                i -= 1;
            }
        }
        return { -1, -1 };
    }

    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        height_ = matrix.size();
        width_ = matrix[0].size();

        int total = height_ * width_;

        int cur_i = 0;
        int cur_j = 0;
        while (visited_.size() < total) {
            auto [next_i, next_j] = GoOneClock(matrix, cur_i, cur_j);
            cur_i = next_i;
            cur_j = next_j;
        }

        return outs_;
    }
};