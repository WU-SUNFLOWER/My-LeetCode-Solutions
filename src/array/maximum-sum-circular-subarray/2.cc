class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        // 计算sum
        int sum = 0;
        for (int num : nums) {
            sum += num;
        }

        // 求解max_sum
        int tmp = nums[0];
        int max_sum = tmp;
        for (int i = 1; i < nums.size(); ++i) {
            tmp = std::max(tmp + nums[i], nums[i]);
            max_sum = std::max(max_sum, tmp);
        }

        // 求解min_sum
        tmp = nums[0];
        int min_sum = tmp;
        for (int i = 1; i < nums.size(); ++i) {
            tmp = std::min(tmp + nums[i], nums[i]);
            min_sum = std::min(min_sum, tmp);
        }

        return min_sum == sum ? max_sum : std::max(sum - min_sum, max_sum);
    }
};