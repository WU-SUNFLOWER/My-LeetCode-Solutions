class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        // <数值, 所属列表的id号>
        int nr_lists = nums.size();
        std::vector<std::pair<int, int>> vec;
        for (int num_list_id = 0; num_list_id < nr_lists; ++num_list_id) {
            for (int num : nums[num_list_id]) {
                vec.emplace_back(num, num_list_id);
            }
        }

        // 排序
        std::sort(vec.begin(), vec.end(), [](const auto& a, const auto& b) {
            return a.first < b.first;
        });

        // <列表id号，窗口内包含多少来自该列表的数>
        std::unordered_map<int, int> window;
        int l = 0;
        int r = 0;
        int ans_len = std::numeric_limits<int>::max();
        int ans_l = -1;
        int ans_r = -1;
        while (l < vec.size() && r <= vec.size()) {
            // 如果窗口[l, r)还没有囊括来自所有list的数值，继续向右扩张
            // 否则更新答案，窗口左边界向右收缩
            if (r < vec.size() && window.size() < nr_lists) {
                ++window[vec[r].second];
                ++r;
                continue;
            }

            if (window.size() == nr_lists) {
                int curr_len = vec[r - 1].first - vec[l].first;
                if (curr_len < ans_len) {
                    ans_len = curr_len;
                    ans_l = l;
                    ans_r = r - 1;
                }
            }
            
            int list_id = vec[l].second;
            ++l;
            if (--window[list_id] == 0) {
                window.erase(list_id);
            }
        }
        return {vec[ans_l].first, vec[ans_r].first};
    }
};