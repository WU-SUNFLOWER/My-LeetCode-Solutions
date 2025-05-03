// tasks[i] = [enqueueTimei, processingTimei]

struct Task {
    int id;
    int arrived_time;
    int duration;

    Task(int id, int arrived_time, int duration)
     : id(id), arrived_time(arrived_time), duration(duration) {}

    void Tick() { --duration; }

    bool IsFinished() { return duration == 0; }
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
    int current_time_ = 1;
    std::optional<Task> current_task_ = std::nullopt;

    std::priority_queue<Task, std::deque<Task>, ArrivedComparer> arriving_tasks_;
    std::priority_queue<Task, std::deque<Task>, PrioComparer> task_pq_;

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

            if (current_task_.has_value()) {
                // 当前任务消耗掉当前时间片
                current_task_->Tick();
                // 如果当前时间片结束后，当前任务执行完毕
                if (current_task_->IsFinished()) {
                    // 调度下一个任务
                    goto pick_next_task;
                } else {
                    // 否则直接进入下一个时间片
                    goto finish;
                }
            }

pick_next_task:
            if (!task_pq_.empty()) {
                current_task_ = task_pq_.top();
                task_pq_.pop();
                ans.emplace_back(current_task_->id);
            } else {
                current_task_ = std::nullopt;
            }            

finish:
            if (current_task_.has_value()) {
                ++current_time_;
            } else {
                current_time_ = arriving_tasks_.top().arrived_time;
            }
        }

        return ans;
    }
};