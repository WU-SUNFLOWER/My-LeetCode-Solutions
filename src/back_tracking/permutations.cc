class Solution {
private:
    std::vector<std::vector<int>> ans_vec_;

public:
    void Search(int start, std::vector<int>& nums) {
        if (start == nums.size() - 1) {
            ans_vec_.emplace_back(nums);
            return;
        }

        for (int i = start; i < nums.size(); ++i) {
            std::swap(nums[start], nums[i]);
            Search(start + 1, nums);
            std::swap(nums[start], nums[i]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        Search(0, nums);
        return ans_vec_;
    }
};