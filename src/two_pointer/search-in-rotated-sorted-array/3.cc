class Solution {
public:
    int FindInLeft(std::vector<int>& nums, int target) {
        int i = 0;
        int j = nums.size() - 1;
        while (i <= j) {
            int mid = i + ((j - i) >> 1);
            // mid落在右侧
            if (nums[mid] < nums[0]) {
                j = mid - 1;
            } 
            // mid落在左侧，正常的二分
            else {
                if (nums[mid] == target) {
                    return mid;
                }
                if (nums[mid] < target) {
                    i = mid + 1;
                } else {
                    j = mid - 1;
                }
            }
        }
        return -1;
    }

    int FindInRight(std::vector<int>& nums, int target) {
        int i = 0;
        int j = nums.size() - 1;
        while (i <= j) {
            int mid = i + ((j - i) >> 1);
            // mid落在左侧
            if (nums[mid] >= nums[0]) {
                i = mid + 1;
            } 
            // mid落在左侧，正常的二分
            else {
                if (nums[mid] == target) {
                    return mid;
                }
                if (nums[mid] < target) {
                    i = mid + 1;
                } else {
                    j = mid - 1;
                }
            }
        }
        return -1;
    }

    int search(vector<int>& nums, int target) {
        if (nums[0] <= target) {
            return FindInLeft(nums, target);
        } else {
            return FindInRight(nums, target);
        }
    }
};