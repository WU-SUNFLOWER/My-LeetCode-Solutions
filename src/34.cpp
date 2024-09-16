class Solution {
public:
    int searchLeft(vector<int>& nums, int target) {
        int i = 0;
        int j = nums.size() - 1;
        while (i <= j) {
            int mid = i + ((j - i) >> 1);
            if (nums[mid] < target) {
                i = mid + 1;
            } 
            // nums[mid] ≥ target
            else {
                j = mid - 1;
            }
        }
        /*
            nums=[5,7,7,8,8,10]
                  ↑ ↑
                  j i
        */
        return (i < nums.size() && nums[i] == target) ? i : -1;
    }
    int searchRight(vector<int>& nums, int target) {
        int i = 0;
        int j = nums.size() - 1;
        while (i <= j) {
            int mid = i + ((j - i) >> 1);
            if (nums[mid] <= target) {
                i = mid + 1;
            } 
            // nums[mid] > target
            else {
                j = mid - 1;
            }
        }
        /*
            nums=[5,7,7,8,8,10]
                      ↑ ↑
                      j i
        */
        return (j >= 0 && nums[j] == target) ? j : -1;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        return {searchLeft(nums, target), searchRight(nums, target)};
    }
};