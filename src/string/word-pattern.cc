class Solution {
public:
    std::deque<std::string> SplitWords(std::string& s) {
        int cur = 0;
        std::string tmp;
        std::deque<std::string> ret;
        while (cur < s.size()) {
            if (s[cur] == ' ' && tmp.size() > 0) {
                ret.emplace_back(std::move(tmp));
                tmp.resize(0);
            } else {
                tmp.push_back(s[cur]);
            }
            ++cur;
        }
        ret.emplace_back(std::move(tmp));
        return ret;
    }

    bool wordPattern(string pattern, string s) {
        auto words = SplitWords(s);
        
        std::unordered_map<char, std::string> pattern_word_map;
        std::unordered_set<std::string> is_mapped;

        for (char ch : pattern) {
            if (words.empty()) {
                return false;
            }
            auto& word_front = words.front();
            if (!pattern_word_map.contains(ch)) {
                if (is_mapped.contains(word_front)) {
                    return false;
                }
                is_mapped.insert(word_front);
                pattern_word_map[ch] = std::move(word_front);
                words.pop_front();
            } else {
                if (pattern_word_map.at(ch) != word_front) {
                    return false;
                }
                words.pop_front();
            }
        }

        return words.empty();
    }
};