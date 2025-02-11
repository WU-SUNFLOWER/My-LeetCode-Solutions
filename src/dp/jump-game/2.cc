class Solution {
public:
    bool canJump(vector<int>& nums) {
        std::vector<bool> can_achieve(nums.size(), false);
        can_achieve[0] = true;

        for (int i = 0; i < nums.size(); ++i) {
            if (!can_achieve[i]) {
                return false;
            }
            for (int j = 1; j <= nums[i] && i + j < nums.size(); ++j) {
                can_achieve[i + j] = can_achieve[i];
            }
        }
        return true;
    }
};