class Solution {
public:
    std::vector<int> findDisappearedNumbers(std::vector<int>& nums) {
        int n = nums.size();
        std::vector<int> answer;

        std::sort(nums.begin(), nums.end());

        int j = 0;
        int size = nums.size();
        for (int i = 1; i <= n; ++i) {
            while (j > 0 && j < size && nums[j] == nums[j - 1]) {
                ++j;
            }
            if (j >= size || nums[j] != i) {
                answer.push_back(i);
            } else {
                ++j;
            }
        }

        return answer;
    }
};