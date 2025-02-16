class Solution {
private:
    const std::unordered_map<int, std::string> special_map_ = {
        { 4,    "IV" },
        { 9,    "IX" },
        { 40,   "XL" },
        { 90,   "XC" },
        { 400,  "CD" },
        { 900,  "CM" },
    };

    const std::vector<std::pair<int, char>> ordered_char_list_ = {
        { 1000, 'M' },
        { 500,  'D' },
        { 100,  'C' },
        { 50,   'L' },
        { 10,   'X' },
        { 5,    'V' },
        { 1,    'I' },
    };

public:
    std::string Convert(int num) {
        if (special_map_.contains(num)) {
            return special_map_.at(num);
        }
        int i = 0;
        std::string ret;
        while (i < ordered_char_list_.size() && num > 0) {
            int cur_num = ordered_char_list_[i].first;
            char cur_ch = ordered_char_list_[i].second;
            if (num >= cur_num) {
                ret.push_back(cur_ch);
                num -= cur_num;
                continue;
            }
            ++i;
        }
        return ret;
    }

    std::string intToRoman(int num) {
        int base = 1;
        std::stack<std::string> strs;
        while (num > 0) {
            int left_num = num % 10;
            strs.push(Convert(left_num * base));
            num /= 10;
            base *= 10;
        }

        std::string ret;
        while (!strs.empty()) {
            ret += strs.top();
            strs.pop();
        }

        return ret;
    }
};