class Solution {
public:
    vector<int> partitionLabels(string s) {
        std::unordered_set<char> char_set;
        std::unordered_map<char, int> appear_first;
        std::unordered_map<char, int> appear_last;
        for (int i = 0; i < s.size(); ++i) {
            if (!char_set.contains(s[i])) {
                char_set.insert(s[i]);
                appear_first[s[i]] = i;
            }
            appear_last[s[i]] = i;
        }

        int last_pos = -1;
        std::vector<int> ans;
        for (int i = 0; i < s.size(); ++i) {
            bool flag = true;
            for (char ch : char_set) {
                if (appear_first[ch] <= i && i < appear_last[ch]) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                ans.push_back(i - last_pos);
                last_pos = i;
            }
        }
        return ans;
    }
};