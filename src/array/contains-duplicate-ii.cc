class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        std::unordered_map<int, std::vector<int>> my_map;
        for (int i = 0; i < nums.size(); ++i) {
            if (my_map.contains(nums[i])) {
                int last = my_map[nums[i]].back();
                if (std::abs(i - last) <= k) {
                    return true;
                }
            }
            my_map[nums[i]].push_back(i);
        }
        return false;
    }
};