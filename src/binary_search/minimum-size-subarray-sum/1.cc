class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        std::vector<int> sums(nums.size() + 1, 0);
        
        for (int i = 1; i <= nums.size(); ++i) {
            sums[i] = sums[i - 1] + nums[i - 1];
        }

        bool find = false;
        int ans = std::numeric_limits<int>::max();
        for (int i = 0; i <= nums.size(); ++i) {
            for (int j = i + 1; j <= nums.size(); ++j) {
                // sums[j] >= target + sums[i]
                if (sums[j] - sums[i] >= target) {
                    ans = std::min(ans, j - i);
                    find = true;
                }
            }
        }

        return find ? ans : 0;
    }
};