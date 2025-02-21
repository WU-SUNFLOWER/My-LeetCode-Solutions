class Solution {
public:
    // 返回true：发生重叠
    // 返回false：没有发生重叠
    bool CheckOverlap(const vector<int>& a, const vector<int>& b) {
        return !(a[1] < b[0] || b[1] < a[0]);
    }

    std::vector<int> Merge(const vector<int>& a, const vector<int>& b) {
        return { std::min(a[0], b[0]), std::max(a[1], b[1]) };
    }

    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        // 1. 确定插入位置
        int insert_pos = intervals.size();
        for (int i = 0; i < intervals.size(); ++i) {
            if (newInterval[0] < intervals[i][0]) {
                insert_pos = i;
                break;
            }
        }

        // 2. 向左合并区间
        int tmp_pos = insert_pos - 1;
        while (tmp_pos >= 0 && CheckOverlap(intervals[tmp_pos], newInterval)) {
            newInterval = std::move(Merge(intervals[tmp_pos], newInterval));
            --tmp_pos;        
        }

        // 3. 输出左侧无法继续被合并的区间
        std::vector<std::vector<int>> ans;
        for (int i = 0; i <= tmp_pos; ++i) {
            ans.emplace_back(std::move(intervals[i]));
        }

        // 4，向右合并区间
        tmp_pos = insert_pos;
        while (tmp_pos < intervals.size() && CheckOverlap(intervals[tmp_pos], newInterval)) {
            newInterval = std::move(Merge(intervals[tmp_pos], newInterval));
            ++tmp_pos;
        }

        // 5. 输出newInterval以及无法被继续合并的右侧区间
        ans.emplace_back(std::move(newInterval));
        for (int i = tmp_pos; i < intervals.size(); ++i) {
            ans.emplace_back(std::move(intervals[i]));
        }

        return ans;
    }
};