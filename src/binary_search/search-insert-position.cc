class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int i = 0;
        int j = nums.size();
        while (i < j) {
            int mid = (i + j) >> 1;
            int num = nums[mid];
            if (num == target) {
                return mid;
            }
            else if (num < target) {
                i = mid + 1;
            }
            else {
                j = mid;
            }
        }
        return i;
    }
};