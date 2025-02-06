class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());

        std::vector<std::vector<int>> ans_vec;

        for (int i = 0; i < nums.size(); ++i) {
            while (1 <= i && i < nums.size() && nums[i - 1] == nums[i]) {
                ++i;
            }

            if (i >= nums.size()) break;

            int target = -nums[i];
            int low = i + 1;
            int high = nums.size() - 1;
            while (low < high) {
                int sum = nums[low] + nums[high];

                if (sum == target) {
                    ans_vec.push_back({ nums[i], nums[low], nums[high] });
                    ++low;
                    --high;
                }
                else if (sum < target) {
                    ++low;
                }
                else {
                    --high;
                }

                while (i + 1 < low && low < nums.size() && nums[low - 1] == nums[low]) {
                    ++low;
                }
                while (low < high && high < nums.size() - 1 && nums[high] == nums[high + 1]) {
                    --high;
                }
            }
        }

        return ans_vec;
    }
};