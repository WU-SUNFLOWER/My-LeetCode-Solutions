class Solution {
public:
    int search(vector<int>& nums, int target) {
        int i = 0;
        int j = nums.size() - 1;

        while (i <= j) {
            int mid = (i + j) >> 1;

            if (nums[mid] == target) {
                return mid;
            }

            // mid落在左半部
            if (nums[mid] > nums[j]) {
                // 看看target和nums[j]是啥关系
                // target在左半部
                if (nums[j] < target) {
                    if (target < nums[mid]) {
                        j = mid - 1;
                    } else {
                        i = mid + 1;
                    }
                }
                // target在右半部,则左哨兵无条件向右移动
                else {
                    i = mid + 1;
                }
            } 
            // mid落在右半部
            else {
                // 看看target和nums[j]是啥关系
                // target在左半部，则右哨兵无条件向左移动
                if (nums[j] < target) {
                    j = mid - 1;
                }
                // target在右半部
                else {
                    if (target < nums[mid]) {
                        j = mid - 1;
                    } else {
                        i = mid + 1;
                    }
                }
            }
        }

        return -1;
    }
};