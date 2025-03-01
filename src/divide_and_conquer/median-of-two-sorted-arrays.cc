class Solution {
public:
    int FindKth(const std::vector<int>& nums_1, int i, const std::vector<int>& nums_2, int j, int k) {
        if (i >= nums_1.size()) {
            return nums_2[j + k - 1];
        }
        if (j >= nums_2.size()) {
            return nums_1[i + k - 1];
        }
        if (k == 1) {
            return std::min(nums_1[i], nums_2[j]);
        }

        int val_1 = (i + k / 2 - 1 < nums_1.size()) ? nums_1[i + k / 2 - 1] : std::numeric_limits<int>::max();
        int val_2 = (j + k / 2 - 1 < nums_2.size()) ? nums_2[j + k / 2 - 1] : std::numeric_limits<int>::max();

        if (val_1 < val_2) {
            return FindKth(nums_1, i + k / 2, nums_2, j, k - k / 2);
        } else {
            return FindKth(nums_1, i, nums_2, j + k / 2, k - k / 2);
        }
    }

    double findMedianSortedArrays(vector<int>& nums_1, vector<int>& nums_2) {
        int total_len = nums_1.size() + nums_2.size();
        if (total_len % 2 == 1) {
            return FindKth(nums_1, 0, nums_2, 0, total_len / 2 + 1);
        } else {
            return (FindKth(nums_1, 0, nums_2, 0, total_len / 2) + 
                    FindKth(nums_1, 0, nums_2, 0, total_len / 2 + 1)) / 2.0;
        }
    }
};