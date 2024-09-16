class Solution {
public:
    int findOnePos(std::vector<int>& nums, int target) {
        int i = 0;
        int j = nums.size() - 1;
        int mid = -1;
        while (i <= j) {
            mid = (i + j) >> 1;
            if (nums[mid] < target) {
                i = mid + 1;
            } 
            else if (nums[mid] > target) {
                j = mid - 1;
            }
            else {
                break;
            }
        }
        return mid;
    }
    bool isMajorityElement(vector<int>& nums, int target) {
        int one_pos = findOnePos(nums, target);
        int count = 0;
        int cur_pos = one_pos;
        while (cur_pos >= 0 && nums[cur_pos] == target) {
            ++count;
            --cur_pos;
        }
        cur_pos = one_pos + 1;
        while (cur_pos < nums.size() && nums[cur_pos] == target) {
            ++count;
            ++cur_pos;
        }
        return count > nums.size() / 2;
    }
};