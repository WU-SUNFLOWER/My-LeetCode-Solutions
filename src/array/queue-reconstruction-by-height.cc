class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        std::sort(people.begin(), people.end(), [](const std::vector<int>& p1, const std::vector<int>& p2) {
            return p1[0] > p2[0] || p1[0] == p2[0] && p1[1] < p2[1];
        });

        std::vector<std::vector<int>> ans;
        for (const auto& cur : people) {
            int height = cur[0];
            int higher_num = cur[1];
            if (ans.size() <= higher_num) {
                ans.push_back(std::move(cur));
            } else {
                ans.insert(ans.begin() + higher_num, std::move(cur));
            }
        }
        return ans;
    }
};