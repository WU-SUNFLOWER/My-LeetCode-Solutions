class Solution {
public:
    int missingNumber(vector<int>& arr) {
        int target_sum = (arr.front() + arr.back()) * (arr.size() + 1) / 2;
        int real_sum = std::accumulate(arr.begin(), arr.end(), 0);
        return target_sum - real_sum;
    }
};