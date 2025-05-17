class Solution {
public:
    std::string reorganizeString(std::string s) {
        int total_len = 0;
        std::unordered_map<char, int> count;
        for (char ch : s) {
            ++count[ch];
            ++total_len;
        }

        std::vector<std::pair<char, int>> letters(count.begin(), count.end());
        std::sort(letters.begin(), letters.end(), [](const auto& a, const auto& b) {
            return a.second > b.second;
        });

        std::string ans(total_len, 0);
        int pos = 0;
        for (auto [ch, cnt] : letters) {
            while (cnt-- > 0) {
                ans[pos] = ch;
                pos += 2;
                if (pos >= total_len) {
                    pos = 1;
                }
            }
        }

        for (int i = 1; i < ans.size(); ++i) {
            if (ans[i] == ans[i - 1]) return "";
        }

        return ans;
    }
};