class Solution {
public:
    int lengthOfLastWord(string s) {
        std::vector<std::string> vec;
        std::string tmp;
        for (char ch : s) {
            if ('a' <= ch && ch <= 'z' || 'A' <= ch && ch <= 'Z') {
                tmp.push_back(ch);
            } else if (tmp.size() > 0) {
                vec.emplace_back(std::move(tmp));
                tmp.clear();
            }
        }
        if (tmp.size() > 0) {
            vec.emplace_back(std::move(tmp));
            tmp.clear();
        }
        return vec.back().size();
    }
};