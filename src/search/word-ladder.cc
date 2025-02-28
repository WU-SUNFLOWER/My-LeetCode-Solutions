class Solution {
public:
    bool CanConvert(const std::string& s1, const std::string& s2) {
        if (s1.size() != s2.size()) {
            return false;
        }
        int diff = 0;
        for (int i = 0; i < s1.size(); ++i) {
            diff += s1[i] != s2[i];
            if (diff > 1) return false;
        }
        return diff == 1;
    }

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        std::queue<std::string> q;
        std::unordered_set<std::string> visited;
        q.push(beginWord);
        visited.insert(beginWord);

        int path = 1;
        while (!q.empty()) {
            int nexts = q.size();
            while (nexts-- > 0) {
                std::string cur = q.front();
                q.pop();

                if (cur == endWord) {
                    return path;
                }

                for (auto& word : wordList) {
                    if (!visited.contains(word) && CanConvert(cur, word)) {
                        q.push(word);
                        visited.insert(word);
                    }
                }
            }
            ++path;
        }

        return 0;
    }
};