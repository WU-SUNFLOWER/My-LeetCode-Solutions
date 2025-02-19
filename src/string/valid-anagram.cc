class Solution {
public:
    bool isAnagram(string s, string t) {
        std::unordered_map<char, int> s_count;
        std::unordered_map<char, int> t_count;
        for (char ch : s) {
            ++s_count[ch];
        }
        for (char ch : t) {
            ++t_count[ch];
        }
        return s_count == t_count;
    }
};