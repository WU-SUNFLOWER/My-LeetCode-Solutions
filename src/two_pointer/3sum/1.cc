class Point {
private:
    int i_, j_, k_;

public:
    Point(int x, int y, int z) {
        if (x == std::min({x, y, z})) {
            i_ = x;
            j_ = std::min(y, z);
            k_ = std::max(y, z);
        } else if (y == std::min({x, y, z})) {
            i_ = y;
            j_ = std::min(x, z);
            k_ = std::max(x, z);
        } else {
            i_ = z;
            j_ = std::min(x, y);
            k_ = std::max(x, y);
        }
    }
    friend bool operator<(const Point& once, const Point& other) {
        return once.i_ < other.i_ ||
               once.i_ == other.i_ && once.j_ < other.j_ ||
               once.i_ == other.i_ && once.j_ == other.j_ && once.k_ < other.k_;
    }
};

class Solution {
public:
    std::vector<std::vector<int>> TwoNumberProblem(std::vector<int>& nums,
                                                   int target) {
        std::unordered_map<int, int> my_map;
        std::vector<std::vector<int>> ans;
        for (int i = 1; i < nums.size(); ++i) {
            int num = nums[i];
            if (my_map.contains(num)) {
                std::vector<int> tmp = {num, my_map.at(num)};
                ans.emplace_back(std::move(tmp));
            } else {
                my_map[target - num] = num;
            }
        }
        return ans;
    }

    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ret;
        std::unordered_set<int> first_num_cache;
        std::set<Point> filter_cache;

        for (int i = 0; i < nums.size(); ++i) {
            std::swap(nums[0], nums[i]);
            int first_num = nums[0];

            if (first_num_cache.contains(first_num)) {
                continue;
            }

            auto ans_vec = TwoNumberProblem(nums, -first_num);
            if (ans_vec.size() > 0) {
                for (auto& ans : ans_vec) {
                    ans.push_back(first_num);

                    Point tmp(ans[0], ans[1], ans[2]);
                    if (!filter_cache.contains(tmp)) {
                        ret.push_back(ans);
                        filter_cache.insert(tmp);
                    }
                }
            }

            first_num_cache.insert(first_num);
        }

        return ret;
    }
};