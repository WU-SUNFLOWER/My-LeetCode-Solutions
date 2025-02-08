class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int64_t max_num = nums[0];
        int64_t min_num = nums[0];
        int64_t ans = max_num;

        for (int i = 1; i < nums.size(); ++i) {
            int64_t num = nums[i];
            int64_t cur_max_num = max_num;
            int64_t cur_min_num = min_num;

            max_num = std::max({ num, num * cur_max_num, num * cur_min_num });
            min_num = std::min({ num, num * cur_max_num, num * cur_min_num });

            ans = std::max(ans, max_num);
        }

        return ans;
    }
};