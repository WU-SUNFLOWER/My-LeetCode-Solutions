class Solution {
public:
    bool canJump(vector<int>& nums) {
        int max_pos = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (max_pos < i) {
                return false;
            }
            max_pos = std::max(max_pos, i + nums[i]);
        }
        return true; 
    }
};