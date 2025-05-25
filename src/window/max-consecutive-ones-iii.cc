class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l = 0;
        int r = 0;
        int ans = 0;
        while (r < nums.size()) {
            // 如果当前r指向1，
            // 或者r指向0，且有翻转额度
            if (nums[r] == 1 || k > 0) {
                if (nums[r] == 0) --k;
                ++r;
                ans = std::max(ans, r - l);
            } else {
                // 翻转额度用光，说明滑动窗口里一定有0存在
                // 从左向右扫描滑动窗口区间，以求将这个0排除出去
                while (nums[l] == 1) ++l;
                // 此时l一定指向0。让我们将滑动窗口左边界l向右收缩，
                // 将该0排除出去，并回收一个翻转额度。
                ++k;
                ++l;
            }
        }
        return ans;
    }
};