class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        std::unordered_map<char, int> counter;

        int max_task_cnt = 0;
        for (char task : tasks) {
            max_task_cnt = std::max(max_task_cnt, ++counter[task]);
        }

        int how_many_tasks_with_max_cnt = 0;
        for (auto [_, cnt] : counter) {
            if (cnt == max_task_cnt) {
                ++how_many_tasks_with_max_cnt;
            }
        }

        return std::max((max_task_cnt - 1) * (n + 1) + how_many_tasks_with_max_cnt, (int)tasks.size());
    }
};