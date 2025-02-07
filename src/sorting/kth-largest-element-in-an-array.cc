class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int pivot = std::rand() % nums.size();
        int pivot_val = nums[pivot];
        std::vector<int> larger;
        std::vector<int> equal;
        std::vector<int> smaller;
        for (int num : nums) {
            if (num > pivot_val) {
                larger.push_back(num);
            }
            else if (num == pivot_val) {
                equal.push_back(num);
            }
            else {
                smaller.push_back(num);
            }
        }
        if (k <= larger.size()) {
            return findKthLargest(larger, k);
        }
        if (k > larger.size() + equal.size()) {
            return findKthLargest(smaller, k - larger.size() - equal.size());
        }
        return pivot_val;
    }
};