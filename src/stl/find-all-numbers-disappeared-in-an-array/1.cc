class Solution {
public:
    std::vector<int> findDisappearedNumbers(std::vector<int>& nums) {
        int n = nums.size();
        std::set<int> answer_set;
        for (int i = 1; i <= n; ++i) {
            answer_set.insert(i);
        }
        for (int num : nums) {
            answer_set.erase(num);
        }
        std::vector<int> answer;
        for (int num : answer_set) {
            answer.push_back(num);
        }
        return answer;
    }
};