class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        std::sort(nums.begin(), nums.end());

        int l = 0;
        int r = nums.back() - nums[0];
        while (l <= r) {
            int mid = l + ((r - l) >> 1);
            // [0, l), [l, r], (r, nums.back() - nums[0]]
            //   <k    unknown           >=k
            if (k <= GetRank(nums, mid)) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }

    // 在整个数组中有多少个数对(nums[slow], nums[fast])的距离是≤dist的？
    int GetRank(const std::vector<int>& nums, int dist) {
        int rank = 0;
        int slow = 0;
        for (int fast = 0; fast < nums.size(); ++fast) {
            while (slow < fast && nums[fast] - nums[slow] > dist) {
                ++slow;
            }
            rank += fast - slow;
        }
        return rank;
    }
};