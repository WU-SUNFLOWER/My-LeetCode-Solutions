class Solution {
private:
    int graph_[2000][2000] = { 0 };

public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // Build our graph!
        std::map<int, int> pre_count;
        for (int i = 0; i < numCourses; ++i) {
            pre_count[i] = 0;
        }
        for (const auto& edge : prerequisites) {
            int to = edge[0];
            int from = edge[1];
            graph_[from][to] = 1;
            pre_count[to] += 1;
        }

        std::vector<int> answer;
        std::queue<int> queue;

        for (const auto& record : pre_count) {
            if (record.second == 0) {
                queue.push(record.first);
            }
        }

        while (!queue.empty()) {
            int cur = queue.front();
            queue.pop();
            answer.push_back(cur);

            for (int next = 0; next < numCourses; ++next) {
                if (graph_[cur][next]) {
                    pre_count[next] -= 1;
                    if (pre_count[next] == 0) {
                        queue.push(next);
                    }
                }
            }
        }

        for (const auto& record : pre_count) {
            if (record.second != 0) {
                return { };
            }
        }

        return answer;
    }
};