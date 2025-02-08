class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        std::vector<int> answer(nums.size(), 0);

        // answer[i] = nums[0] * nums[1] * ... * nums[i - 1]
        answer[0] = 1;
        for (int i = 1; i < nums.size(); ++i) {
            answer[i] = answer[i - 1] * nums[i - 1];
        }

        int mul_in_right = 1;
        for (int j = nums.size() - 1; j >= 0; --j) {
            answer[j] *= mul_in_right;
            mul_in_right *= nums[j];
        }

        return answer;
    }
};