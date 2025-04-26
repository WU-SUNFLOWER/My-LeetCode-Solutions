class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int len = nums.size();
        int l = 0;
        int r = 0;
        int sum = 0;
        int ans = std::numeric_limits<int>::max();
        while (r < len) {
            sum += nums[r];
            while (sum >= target) {
                ans = std::min(ans, r - l + 1);

                sum -= nums[l];
                ++l;  // 窗口左边界收缩
            }
            ++r;  // 窗口右边界扩张
        }
        return ans == std::numeric_limits<int>::max() ? 0 : ans;
    }
};