#define N 5

class Solution {
public:
    vector<vector<int>> highFive(vector<vector<int>>& items) {
        std::map<int, std::priority_queue<int>> heaps;
        for (auto& item: items) {
            heaps[item[0]].push(item[1]);
        }
        std::vector<std::vector<int>> ans; 
        for (auto& pair: heaps) {
            int id = pair.first;
            int sum = 0;
            std::priority_queue<int>& heap = pair.second;
            for (int i = 0; i < N; ++i) {
                sum += heap.top();
                heap.pop();
            }
            ans.push_back({id, sum / N});
        }
        return ans;
    }
};