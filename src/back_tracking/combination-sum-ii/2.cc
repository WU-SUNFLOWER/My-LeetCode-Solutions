class Solution {
private:
    std::vector<std::vector<int>> ans_;

public:
    using T = std::map<int, int>::iterator;

    void Solve(T bucket, T end, std::vector<int>& record, int sum, int target) {
        if (sum == target) {
            ans_.emplace_back(record);
            return;
        } else if (sum > target) {
            return;
        }

        if (bucket == end) {
            return;
        }

        // Case 1. 从当前桶中取数字
        if (bucket->second > 0) {
            bucket->second -= 1;
            record.emplace_back(bucket->first);
            Solve(bucket, end, record, sum + bucket->first, target);
            record.pop_back();
            bucket->second += 1;
        }

        // Case 2. 从下一个桶中取数字
        Solve(std::next(bucket), end, record, sum, target);
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        // <桶中装的数字, 桶中有几个这样的数字> 
        std::map<int, int> buckets;
        for (int num : candidates) {
            buckets[num] += 1;
        }

        std::vector<int> record;
        Solve(buckets.begin(), buckets.end(), record, 0, target);
        return ans_;
    }
};