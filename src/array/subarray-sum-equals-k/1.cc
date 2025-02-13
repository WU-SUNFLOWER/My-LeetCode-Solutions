class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        std::vector<int> sum(nums.size() + 1, 0);
    
        for (int i = 1; i <= nums.size(); ++i) {
            sum[i] = sum[i - 1] + nums[i - 1];
        }

        int ans = 0;
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = i + 1; j <= nums.size(); ++j) {
                if (sum[j] - sum[i] == k) {
                    ++ans;
                }
            }
        }

        return ans;
    }
};