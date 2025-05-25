class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        std::unordered_map<std::string, int> count_map;
        for (const auto& word : words) {
            count_map[word] += 1;
        }

        int nr_words = words.size();
        int word_len = words[0].size();
        int window_len = nr_words * word_len;
        std::vector<int> ans;
        for (int offset = 0; offset < word_len; ++offset) {
            int step = 0;  // 当前窗口中已经被记录的单词数
            int window_start_pos = offset;
            std::unordered_map<std::string, int> window;
            for (int pos = offset; pos < s.size(); pos += word_len) {
                std::string curr_word = s.substr(pos, word_len);
                // 如果扫描到非法单词，整个窗口直接移动到该单词右侧
                // ，并且清空所有记录进度
                if (!count_map.contains(curr_word)) {
                    window_start_pos = pos + word_len;
                    window.clear();
                    step = 0;
                    continue;
                }
                // 将当前单词记录进窗口
                ++window[curr_word];
                ++step;
                // 如果已经满一个窗口的大小了
                if (step >= nr_words) {
                    if (window == count_map) {
                        ans.emplace_back(window_start_pos);
                    }
                    --window[s.substr(window_start_pos, word_len)];
                    window_start_pos += word_len;
                }
            }
        }

        return ans;
    }
};