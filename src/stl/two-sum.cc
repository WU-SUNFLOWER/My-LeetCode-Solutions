class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        // record<num, pos>
        std::unordered_map<int, int> record;
        for (int i = 0; i < numbers.size(); ++i) {
            if (record.count(target - numbers[i]) > 0) {
                return { i, record[target - numbers[i]] };
            } else {
                record[numbers[i]] = i;
            }
        }
        return {};
    }
};