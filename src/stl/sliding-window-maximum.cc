class Solution {
public:
    std::vector<int> maxSlidingWindow(std::vector<int>& nums, int k) {
        std::vector<int> answer;
        std::deque<int> dq;
        for (int i = 0; i < nums.size(); ++i) {
            // 将原先滑动窗口中的第一个元素摘除
            if (!dq.empty() && dq.front() == i - k) {
                dq.pop_front();
            }
            // 将滑动窗口中比新元素小的元素全部淘汰掉
            while (!dq.empty() && nums[dq.back()] <= nums[i]) {
                dq.pop_back();
            }
            // 将新元素纳入滑动窗口
            dq.push_back(i);
            // 双端队列头部（滑动窗口左侧）的即为当前轮的最大值
            if (i >= k - 1) answer.push_back(nums[dq.front()]);
        }
        return answer;
    }
};