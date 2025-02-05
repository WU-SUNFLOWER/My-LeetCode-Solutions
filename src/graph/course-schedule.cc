class Solution {
private:
    int graph_[2000][2000] = { 0 };

public:
    bool WithoutInDegree(int node, int numCourses) {
        for (int other = 0; other < numCourses; ++other) {
            if (graph_[other][node]) {
                return false;
            }
        }
        return true;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // Initialize `roots`
        std::set<int> roots;
        for (int i = 0; i < numCourses; ++i) {
            roots.insert(i);
        }

        // Build graph
        for (const auto& edge : prerequisites) {
            int from = edge[1];
            int to = edge[0];
            graph_[from][to] = 1;
            roots.erase(to);
        }

        std::queue<int> q;
        // Push roots into q
        for (int root : roots) {
            q.push(root);
        }

        int visited_cnt = 0;
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            ++visited_cnt;

            for (int next = 0; next < numCourses; ++next) {
                if (graph_[cur][next]) {
                    graph_[cur][next] = 0;
                    if (WithoutInDegree(next, numCourses)) {
                        q.push(next);
                    }
                }
            }
        }

        return visited_cnt == numCourses;
    }
};