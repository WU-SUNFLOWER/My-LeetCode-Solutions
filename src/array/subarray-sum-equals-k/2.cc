class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // <sum, 出现次数>
        std::unordered_map<int, int> my_map;
        int sum = 0;
        ++my_map[sum];

        int ans = 0;
        for (int num : nums) {
            sum += num;
            if (my_map.contains(sum - k)) {
                ans += my_map[sum - k];
            }
            ++my_map[sum];
        }
        return ans;
    }
};