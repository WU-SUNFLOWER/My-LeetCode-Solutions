class Solution {
private:
    void PrintVec(vector<int>& nums) {
        for (int num : nums) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }

public:
    void nextPermutation(vector<int>& nums) {
        int i = nums.size() - 2;
        while (i >= 0) {
            if (nums[i] >= nums[i + 1]) {
                --i;
            } else {
                break;
            }
        }

        if (i < 0) {
            std::reverse(nums.begin(), nums.end());
            return;
        }

        int j = nums.size() - 1;
        while (j > i) {
            if (nums[j] > nums[i]) {
                break;
            }
            --j;
        }

        std::swap(nums[i], nums[j]);

        std::reverse(nums.begin() + i + 1, nums.end());
    }
};