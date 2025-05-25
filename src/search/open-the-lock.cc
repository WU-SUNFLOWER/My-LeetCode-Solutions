class Solution {
public:
    int openLock(std::vector<std::string>& deadends, std::string target) {
        std::unordered_set<std::string> visited;
        for (auto& dead_string : deadends) {
            visited.insert(std::move(dead_string));
        }

        if (visited.contains("0000")) {
            return -1;
        }

        std::queue<std::string> q;
        q.emplace("0000");
        visited.insert("0000");

        int step = 0;
        while (!q.empty()) {
            int len = q.size();
            while (len > 0) {
                auto curr = std::move(q.front());
                q.pop();

                if (curr == target) {
                    return step;
                }

                for (int i = 0; i < 4; ++i) {
                    char saved = curr[i];

                    curr[i] = saved == '9' ? '0' : (saved + 1);
                    if (!visited.contains(curr)) {
                        q.emplace(curr);
                        visited.insert(curr);
                    }
                    curr[i] = saved == '0' ? '9' : (saved - 1);
                    if (!visited.contains(curr)) {
                        q.emplace(curr);
                        visited.insert(curr);
                    }

                    curr[i] = saved;
                }

                --len;
            }
            ++step;
        }

        return -1;
    }
};