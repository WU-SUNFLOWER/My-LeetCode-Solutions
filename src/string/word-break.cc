class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        std::queue<std::string> q;
        std::unordered_set<std::string> visited;

        q.push(s);
        visited.insert(std::move(s));

        while (!q.empty()) {
            std::string cur = std::move(q.front());
            q.pop();

            for (const auto& word : wordDict) {
                if (cur.find(word) == 0) {
                    std::string left_str = cur.substr(word.size());

                    if (left_str.size() == 0) {
                        return true;
                    }

                    if (visited.contains(left_str)) {
                        continue;
                    }

                    visited.insert(left_str);
                    q.push(left_str);
                }
            }
        }

        return false;
    }
};