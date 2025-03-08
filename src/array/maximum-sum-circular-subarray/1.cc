class Solution {
private:
    int len_;
public:
    int MaxSubArraySum(const std::vector<int>& nums, int start) {
        int sum = nums[start];
        int ans = sum;
        int cur = (start + 1) % len_;
        while (cur != start) {
            sum = std::max(sum + nums[cur], nums[cur]);
            ans = std::max(ans, sum);
            cur = (cur + 1) % len_;
        }
        return ans;
    }

    int maxSubarraySumCircular(vector<int>& nums) {
        len_ = nums.size();

        int ans = std::numeric_limits<int>::min();
        for (int i = 0; i < len_; ++i) {
            ans = std::max(ans, MaxSubArraySum(nums, i));
        }
        return ans;
    }
};