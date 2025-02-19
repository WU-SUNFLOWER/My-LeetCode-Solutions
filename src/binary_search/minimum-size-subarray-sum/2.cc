class Solution {
public:
    int Search(std::vector<int>& ar, int begin, int target) {
        int i = begin;
        int j = ar.size();
        while (i < j) {
            // 找到了向左找
            int mid = (i + j) >> 1;
            if (ar[mid] >= target) {
                j = mid;
            } else {
                i = mid + 1;
            }
        }
        return i;
    }

    int minSubArrayLen(int target, vector<int>& nums) {
        std::vector<int> sums(nums.size() + 1, 0);

        for (int i = 1; i <= nums.size(); ++i) {
            sums[i] = sums[i - 1] + nums[i - 1];
        }

        bool find = false;
        int ans = std::numeric_limits<int>::max();
        for (int i = 0; i <= nums.size(); ++i) {
            int j = Search(sums, i + 1, target + sums[i]);
            if (j <= nums.size()) {
                ans = std::min(ans, j - i);
                find = true;                
            }
        }

        return find ? ans : 0;
    }
};