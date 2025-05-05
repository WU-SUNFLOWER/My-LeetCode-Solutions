class Solution {
public:
    vector<int> trainingPlan(vector<int>& nums) {
        std::vector<int> odd;
        std::vector<int> even;
        for (int num : nums) {
            if (num % 2 == 1) {
                odd.emplace_back(num);
            } else {
                even.emplace_back(num);
            }
        }
        odd.insert(odd.end(), 
                   std::make_move_iterator(even.begin()),
                   std::make_move_iterator(even.end()));
        return odd;
    }
};