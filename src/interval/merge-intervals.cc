class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        std::sort(intervals.begin(), intervals.end(), [](const vector<int>& v1, const vector<int>& v2) {
            return v1[0] < v2[0];
        });
        
        std::vector<std::vector<int>> ans;
        ans.push_back(intervals[0]);

        for (int i = 1; i < intervals.size(); ++i) {
            std::vector<int> last = ans.back();
            std::vector<int>& cur = intervals[i];

            if (!(last[1] < cur[0])) {
                ans.pop_back();
                ans.push_back({ last[0], std::max(last[1], cur[1]) });
            } else {
                ans.push_back(cur);
            }
        }

        return ans;
    }
};