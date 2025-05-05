#define IS_ODD(x) (((x) & 1) == 1)
#define IS_EVEN(x) (((x) & 1) == 0)

class Solution {
public:
    vector<int> trainingPlan(vector<int>& nums) {
        int i = 0;
        int j = nums.size() - 1;
        while (i < j) {
            while (i < j && IS_ODD(nums[i])) ++i;
            while (i < j && IS_EVEN(nums[j])) --j;
            std::swap(nums[i], nums[j]);
        }
        return nums;
    }
};