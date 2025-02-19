class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }

        std::unordered_map<char, char> my_map;
        std::unordered_set<char> is_mapped;

        for (int i = 0; i < s.size(); ++i) {
            if (!my_map.contains(s[i])) {
                if (!is_mapped.contains(t[i])) {
                    my_map[s[i]] = t[i];
                    is_mapped.insert(t[i]);
                } else {
                    return false;
                }
            } else {
                char expect = my_map[s[i]];
                if (expect != t[i]) {
                    return false;
                }
            }
        }

        return true;
    }
};