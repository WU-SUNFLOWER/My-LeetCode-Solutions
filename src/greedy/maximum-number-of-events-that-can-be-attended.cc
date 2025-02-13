#define MAX_DAY (1e5 + 1)

class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        // start[i] 在第i天哪些会议开始启动
        std::vector<std::vector<int>> start(MAX_DAY);
        for (int event_id = 0; event_id < events.size(); ++event_id) {
            int start_day = events[event_id][0];
            start[start_day].push_back(event_id);
        }
        
        int ans = 0;
        // 通过优先队列获取结束最早的活动
        std::priority_queue<int, std::vector<int>, std::greater<>> pq;
        for (int cur_day = 1; cur_day < MAX_DAY; ++cur_day) {
            // 将当前天开始启动的活动，加入到优先队列当中
            for (int event_id : start[cur_day]) {
                pq.push(events[event_id][1]);
            }
            // 淘汰掉优先队列中所有已经结束的活动
            while (!pq.empty() && pq.top() < cur_day) {
                pq.pop();
            }
            // 从优先队列中取出正在进行中的，且结束时间最早的活动
            if (!pq.empty()) {
                pq.pop();
                ++ans;
            }
        }

        return ans;
    }
};