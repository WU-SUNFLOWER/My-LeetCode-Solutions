class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        const std::string& first_str = strs[0];
        for (int i = 0; i < first_str.size(); ++i) {
            for (const auto& other_str : strs) {
                if (other_str.size() <= i || first_str[i] != other_str[i]) {
                    return first_str.substr(0, i);
                }
            }
        }
        return first_str;
    }
};