class Solution {
public:
    int findMin(vector<int>& nums) {
        int i = 0;
        int j = nums.size() - 1;
        while (i <= j) {
            // [0, i - 1], [i, j], [j + 1, nums.size())
            //  最小值左侧  unknown   最小值或最小值右侧

            // mid指向第一段
            // 这种情况下，最小值一定在mid右侧
            if (nums.back() < nums[mid]) {
                i = mid + 1;
            } 
            // mid指向第二段，或数组没有发生过旋转
            else {
                j = mid - 1;
            }
        }
        // i = j + 1
        //   [0, j],      [i, nums.size())
        // 最小值左侧     最小值或最小值右侧
        return nums[i];
    }
};