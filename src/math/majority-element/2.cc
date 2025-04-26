class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate;
        int vote = 0;
        // 摩尔投票，找出数组中出现次数最多的元素
        for (int i = 0; i < nums.size(); ++i) {
            if (vote == 0) {
                candidate = nums[i];
            }
            if (nums[i] == candidate) {
                ++vote;
            } else {
                --vote;
            }
        }
        return candidate;
    }
};