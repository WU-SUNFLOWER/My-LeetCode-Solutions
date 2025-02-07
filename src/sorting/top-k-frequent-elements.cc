class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::unordered_map<int, int> count;
        for (int num : nums) {
            ++count[num];
        }

        std::unordered_map<int, std::vector<int>> bucket;
        for (auto [num, cnt] : count) {
            bucket[cnt].push_back(num);
        }

        std::vector<int> ans;
        for (int cnt = nums.size(); cnt >= 0; --cnt) {
            if (bucket.contains(cnt)) {
                for (int num : bucket[cnt]) {
                    ans.push_back(num);
                    if (ans.size() == k) {
                        return ans;
                    }
                }
            }
        }
        return ans;
    } 
};