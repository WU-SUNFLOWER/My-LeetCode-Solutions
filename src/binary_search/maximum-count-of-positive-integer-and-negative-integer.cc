class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int i = 0;
        int j = nums.size();

        int mid, mid_val;
        while (i < j) {
            mid = (i + j) >> 1;
            mid_val = nums[mid];
            if (mid_val == 0) {
                break;
            }
            else if (mid_val < 0) {
                i = mid + 1;
            }
            else {
                j = mid;
            }
        }

        int l = mid;
        int r = mid;
        while (0 <= l && nums[l] >= 0) {
            --l;
        }
        while (r < nums.size() && nums[r] <= 0) {
            ++r;
        }
        
        return std::max(l + 1, (int)nums.size() - r);
    }
};