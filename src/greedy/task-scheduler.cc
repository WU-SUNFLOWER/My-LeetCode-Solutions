class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        std::unordered_map<char, int> task_count;

        for (char task : tasks) {
            task_count[task] += 1;
        }

        int max_task_count = 0;
        for (auto [_, cur_task_count] : task_count) {
            max_task_count = std::max(max_task_count, cur_task_count);
        }

        int how_many_tasks_with_max_count = 0;
        for (auto [_, cur_task_count] : task_count) {
            if (cur_task_count == max_task_count) {
                ++how_many_tasks_with_max_count;
            }
        }

        return std::max((int)tasks.size(), (n + 1) * (max_task_count - 1) + how_many_tasks_with_max_count);
    }
};