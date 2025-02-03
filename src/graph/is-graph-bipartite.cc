class Solution {
 private:
    enum Color {kWhite, kRed, kBlack};
    std::map<int, Color> color_map_;

#define IS_WHITE(node) (color_map_.count(node) <= 0)
#define IS_RED(node) (color_map_.count(node) > 0 && color_map_[node] == Color::kRed)
#define IS_BLACK(node) (color_map_.count(node) > 0 && color_map_[node] == Color::kBlack)
#define SET_COLOR(node, color) (color_map_[node] = color)

 public:
    bool BFS(int root, std::vector<vector<int>>& graph) {
        // current root node has already been verified in another sub graph!
        if (!IS_WHITE(root)) {
            return true;
        }

        std::queue<int> q;
        SET_COLOR(root, Color::kBlack);
        q.push(root);

        while (!q.empty()) {
            int cur = q.front();
            q.pop();

            for (int next : graph[cur]) {
                if (IS_WHITE(next)) {
                    SET_COLOR(next, IS_RED(cur) ? Color::kBlack : Color::kRed);
                    q.push(next);
                    continue;
                }

                if (IS_BLACK(cur) && IS_BLACK(next) || IS_RED(cur) && IS_RED(next)) {
                    return false;
                }
            }
        }
        return true;
    }

    bool isBipartite(std::vector<vector<int>>& graph) {
        for (int i = 0; i < graph.size(); ++i) {
            if (!BFS(i, graph)) {
                return false;
            }
        }
        return true;
    }
};