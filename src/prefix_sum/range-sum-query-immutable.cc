class NumArray {
private:
    std::vector<int> sum_;

public:
    NumArray(vector<int>& nums) {
        sum_.resize(nums.size());
        sum_[0] = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            sum_[i] = sum_[i - 1] + nums[i];
        }
    }
    
    int sumRange(int left, int right) {
        if (0 <= left - 1) {
            return sum_[right] - sum_[left - 1];
        } else {
            return sum_[right];
        }
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */