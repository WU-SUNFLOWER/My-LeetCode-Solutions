/*
  [10,5,2,6]

  [10]      => 以10为右端点的子数组有1个 => [10]
  [10,5]    => 以5为右端点的子数组有2个  => [10, 5], [5]
  [5, 2]    => 以2为右端点的子数组有2个  => [5, 2], [2]
  [5, 2, 6] => 以6为右端点的子数组有3个  => [5, 2, 6], [2, 6], [6]
*/

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k <= 1) {
            return 0;
        }
        
        int window = 1;
        int l = 0;
        int r = 0;
        int ans = 0;
        while (r < nums.size()) {
            window *= nums[r];
            while (window >= k) {
                window /= nums[l];
                ++l;
            }
            ans += r - l + 1;
            ++r;
        }
        return ans;
    }
};