// tasks[i] = [enqueueTimei, processingTimei]

struct Task {
    int id;
    int64_t arrived_time;
    int64_t duration;
    int64_t finished_time = 0;

    Task(int id, int64_t arrived_time, int64_t duration)
     : id(id), arrived_time(arrived_time), duration(duration) {}
};

struct ArrivedComparer {
    // 返回true <=> task_1的优先级低于task_2的优先级 <=> task_2会被放在堆顶
    bool operator()(const Task& task_1, const Task& task_2) {
        return task_1.arrived_time > task_2.arrived_time;
    }
};

struct PrioComparer {
    // 返回true <=> task_1的优先级低于task_2的优先级 <=> task_2会被放在堆顶
    bool operator()(const Task& task_1, const Task& task_2) {
        return task_1.duration > task_2.duration ||
               task_1.duration == task_2.duration && task_1.id > task_2.id;
    }
};

class Solution {
private:
    int64_t current_time_ = 1;
    std::optional<Task> current_task_ = std::nullopt;

    std::priority_queue<Task, std::vector<Task>, ArrivedComparer> arriving_tasks_;
    std::priority_queue<Task, std::vector<Task>, PrioComparer> task_pq_;

public:
    bool HasTaskArrived() {
        if (arriving_tasks_.empty()) {
            return false;
        }

        const auto& next_task = arriving_tasks_.top();
        if (next_task.arrived_time <= current_time_) {
            return true;
        }

        return false;
    }

    vector<int> getOrder(vector<vector<int>>& tasks) {
        int id = 0;
        for (const auto& task : tasks) {
            arriving_tasks_.emplace(id++, task[0], task[1]);
        }

        std::vector<int> ans;
        while (!arriving_tasks_.empty() || 
               !task_pq_.empty()) 
        {
            // 检查是否有任务抵达
            while (HasTaskArrived()) {
                // 有任务抵达，取出任务，投入等待队列
                task_pq_.emplace(arriving_tasks_.top());
                arriving_tasks_.pop();
            }

            if (!current_task_.has_value() || current_task_->finished_time <= current_time_) {
                if (!task_pq_.empty()) {
                    current_task_ = task_pq_.top();
                    current_task_->finished_time = 
                        current_time_ + current_task_->duration;
                    task_pq_.pop();
                    ans.emplace_back(current_task_->id);
                } else {
                    current_task_ = std::nullopt;
                }
            }

            int64_t time_1 = std::numeric_limits<int64_t>::max();
            int64_t time_2 = std::numeric_limits<int64_t>::max();

            if (current_task_.has_value()) {
                time_1 = current_task_->finished_time;
            }

            if (!arriving_tasks_.empty()) {
                time_2 = arriving_tasks_.top().arrived_time;
            }

            current_time_ = std::min(time_1, time_2);
        }

        return ans;
    }
};