class Solution {
public:
    void InsertionSort(std::vector<int>& nums, int low, int high) {
        for (int i = low + 1; i <= high; ++i) {
            for (int j = i; 0 < j && nums[j - 1] > nums[j]; --j) {
                std::swap(nums[j - 1], nums[j]);
            }
        }
    }

    // [low, high]
    void QuickSort(std::vector<int>& nums, int low, int high) {
        if (low >= high) return;
        
        int len = high - low + 1;
        if (len < 25) {
            InsertionSort(nums, low, high);
            return;
        }
        
        int pivot_idx = ::rand() % len + low;
        int pivot = nums[pivot_idx];
        // 此时nums[pivot_idx]在逻辑上为空，我们用nums[low]来填充
        // 之后nums[low]在逻辑上为空
        nums[pivot_idx] = nums[low];

        int i = low;
        int j = high;

        while (i < j) {
            while (i < j && pivot <= nums[j]) {
                --j;
            }
            nums[i] = nums[j];

            while (i < j && nums[i] <= pivot) {
                ++i;
            }
            nums[j] = nums[i];
        }

        nums[i] = pivot;

        QuickSort(nums, low, i - 1);
        QuickSort(nums, i + 1, high);
    }

    vector<int> sortArray(vector<int>& nums) {
        QuickSort(nums, 0, nums.size() - 1);
        return nums;
    }
};