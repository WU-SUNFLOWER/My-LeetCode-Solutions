class Solution {
public:
    int FindInLeft(const std::vector<int>& nums, int target) {
        int i = 0;
        int j = nums.size();
        while (i < j) {
            int mid = (i + j) >> 1;
            if (nums[mid] < target) {
                i = mid + 1;
            }
            else {
                j = mid;
            }
        }
        return i;
    }

    int FindInRight(const std::vector<int>& nums, int target) {
        int i = 0;
        int j = nums.size();
        while (i < j) {
            int mid = (i + j) >> 1;
            if (nums[mid] <= target) {
                i = mid + 1;
            }
            else {
                j = mid;
            }
        }
        return i;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.size() == 0) {
            return { -1, -1 };
        }

        int l = FindInLeft(nums, target);
        int r = FindInRight(nums, target);
        if (l >= nums.size() || nums[l] != target) {
            return { -1, -1 };
        }

        return { l, r - 1 };
    }
};