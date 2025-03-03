class Solution {
public:
    string minWindow(string s, string t) {
        std::unordered_map<char, int> window;  // 这个是滑动窗口
        std::unordered_map<char, int> t_counter;

        for (char ch : t) {
            ++t_counter[ch];
        }

        std::string ans;
        int count = 0;
        for (int l = 0, r = 0; r < s.size(); ++r) {
            ++window[s[r]];
            // 统计s中可以涵盖t的有效字符
            if (window[s[r]] <= t_counter[s[r]]) {
                ++count;
            }

            // 滑动窗口右半部分中的字符足已涵盖t，
            // 故滑动窗口向右搜索，削减掉左侧的无效字符
            while (window[s[l]] > t_counter[s[l]]) {
                --window[s[l]];
                ++l;
            }

            // 如果当前滑动窗口中已涵盖t中的所有字符，那么记录答案
            if (count == t.size() && (ans.empty() || r - l + 1 < ans.size())) {
                ans = s.substr(l, r - l + 1);
            }
        }

        return ans;
    }
};