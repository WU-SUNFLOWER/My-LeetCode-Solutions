class Solution {
public:
    string crackPassword(vector<int>& password) {
        std::vector<std::string> elements;
        int total_length = 0;
        for (int num : password) {
            auto elem = std::to_string(num);
            total_length += elem.size();
            elements.emplace_back(std::move(elem));
        }
        std::sort(elements.begin(), elements.end(), [](auto& a, auto& b) {
            return (a + b) < (b + a);
        });
        std::string ans;
        ans.reserve(total_length);
        for (const auto& elem : elements) {
            ans += elem;
        }
        return ans;
    }
};