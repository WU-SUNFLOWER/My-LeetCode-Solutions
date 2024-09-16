class Solution {
public:
    static bool compareByStartTime(vector<int>& a, vector<int>& b) {
        //assert(a.size() == 2);
        //assert(b.size() == 2);
        return a[0] < b[0];
    }
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        int size = intervals.size();
        if (size <= 1) return true;
        std::sort(intervals.begin(), intervals.end(),
            compareByStartTime);
        for (int i = 1; i < size; ++i) {
            int endOfLast = intervals[i - 1][1];
            int startOfCur = intervals[i][0];
            if (endOfLast > startOfCur) {
                return false;
            }
        } 
        return true;
    }
};