class Solution {
public:
    vector<vector<int>> findMissingRanges(vector<int>& nums, int lower, int upper) {
        std::vector<std::vector<int>> ans;
        if (nums.size() > 0) {
            int last = lower;
            int num = nums[0];
            if (num > last) {
                ans.push_back({last, num - 1});
                last = num;
            }
            for (int i = 1; i < nums.size(); ++i) {
                num = nums[i];
                if (num > last + 1) {
                    ans.push_back({last + 1, num - 1});
                }
                last = num;                
            }
            if (last < upper) {
                ans.push_back({last + 1, upper});
            }
        } else {
            ans.push_back({lower, upper});
        }
        return ans;
    }
};