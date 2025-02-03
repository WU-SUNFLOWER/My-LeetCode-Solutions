class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i = 0;
        int j = nums.size() - 1;
        while (i < j) {
            int sum = nums[i] + nums[j];
            if (sum == target) {
                break;
            }
            if (sum < target) {
                ++i;
            } else {
                --j;
            }
        }
        return { i + 1, j + 1 };
    }
};