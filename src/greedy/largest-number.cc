class Solution {
public:
    std::string largestNumber(std::vector<int>& nums) {
        std::vector<std::string> str_nums;
        int buffer_size = 0;
        for (int num : nums) {
            auto str_num = std::to_string(num);
            buffer_size += str_num.size();
            str_nums.emplace_back(std::move(str_num));
        }

        std::sort(str_nums.begin(), str_nums.end(), [](const std::string& a, const std::string& b) {
            auto str_num_1 = a + b;
            auto str_num_2 = b + a; 
            return str_num_1 > str_num_2;
        });

        std::string ans;
        ans.reserve(buffer_size);
        for (auto& str_num : str_nums) {
            ans += str_num;
        }

        while (ans[0] == '0' && ans.size() > 1) {
            ans.erase(0, 1);
        }

        return ans;
    }
};