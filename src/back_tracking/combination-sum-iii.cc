class Solution {
private:
    std::vector<std::vector<int>> ans_;

public:
    void Solve(std::vector<int>& record, const int k, 
               int base, int sum, const int target) 
    {
        if (sum == target) {
            if (record.size() == k) {
                ans_.emplace_back(record);
            }
            return;
        }
        
        if (sum > target) {
            return;
        }
        
        if (record.size() >= k) {
            return;
        }

        while (base <= 9) {
            record.emplace_back(base);
            Solve(record, k, base + 1, sum + base, target);
            record.pop_back();
            ++base;
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        std::vector<int> record;
        Solve(record, k, 1, 0, n);
        return ans_;
    }
};