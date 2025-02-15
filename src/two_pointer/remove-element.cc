class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0;
        int j = nums.size() - 1;

        while (i <= j) {
            if (nums[i] != val) {
                ++i;
            } else {
                // 在nums[i]右侧查找可以与nums[i]交换位置的元素
                while (i < j && nums[j] == val) --j;
                // 如果没有找到，说明nums[i]无法被交换出去，直接返回区间[0, i)即可
                if (!(i < j)) return i; 
                std::swap(nums[i], nums[j]);
            }
        }

        return i;
    }
};