class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        // nums[i] => nums[(i + k) % nums.size()]
        const int len = nums.size();
        std::vector<int> new_nums(len, 0);
        for (int i = 0; i < len; ++i) {
            new_nums[(i + k) % len] = nums[i];
        }
        nums = std::move(new_nums);
    }
};