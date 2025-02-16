class Solution {
public:
    bool Check(int start, vector<int>& gas, vector<int>& cost) {
        int cur = start;
        int len = gas.size();
        int oil = gas[cur];

        do {
            int next = (cur + 1) % len;
            oil -= cost[cur]; // 从cur开车到next，需要消耗油

            if (oil < 0) {
                return false;
            }

            oil += gas[next];  // 抵达下一站后，可以补充油
            cur = next;
        } while (cur != start);

        return true;
    }

    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        // 第 i 个加油站有汽油 gas[i] 升
        // 从第 i 个加油站开往第 i+1 个加油站需要消耗汽油 cost[i] 升
        for (int start = 0; start < gas.size(); ++start) {
            if (Check(start, gas, cost)) {
                return start;
            }
        }
        return -1;
    }
};