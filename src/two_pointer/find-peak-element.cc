class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int len = nums.size();
        if (len <= 1) return 0;

        int i = 0;
        int j = len;

        while (i < j) {
            int mid = (i + j) >> 1;
            if (mid + 1 < len && nums[mid] < nums[mid + 1]) {
                i = mid + 1;
            } else {
                j = mid;
            }
        }

        return i;
    }
};