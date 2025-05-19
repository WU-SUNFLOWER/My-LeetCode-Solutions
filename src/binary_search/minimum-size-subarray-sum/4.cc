class Solution {
public:
    // [0, r_pos)
    // 找到最右边的≤max_target的位置
    int Find(const std::vector<int>& ar, int r_pos, int max_target) {
        int i = 0;
        int j = r_pos;
        while (i < j) {
            int mid = i + ((j - i) >> 1);
            //  [0, i - 1],  [i, j),  [j, r_pos]
            //  ≤max_target  unknown   >max_target
            if (ar[mid] <= max_target) {
                i = mid + 1;
            } else {
                j = mid;
            }
        }
        return i - 1;
    }

    int minSubArrayLen(int target, std::vector<int>& nums) {
        std::vector<int> sums(nums.size() + 1, 0);
        for (int i = 1; i <= nums.size(); ++i) {
            sums[i] = sums[i - 1] + nums[i - 1];
        }
        int ans = std::numeric_limits<int>::max();
        for (int i = 1; i <= nums.size(); ++i) {
            int max_target = sums[i] - target;
            if (max_target >= 0) {
                int j = Find(sums, i, max_target);
                ans = std::min(ans, i - j);
            }
        }
        return ans == std::numeric_limits<int>::max() ? 0 : ans;
    }
};