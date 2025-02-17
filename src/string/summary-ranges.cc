class Solution {
public:
    std::string BuildNumberStr(int num) {
        std::stringstream ss;
        std::string ret;
        ss << num;
        ss >> ret;
        return ret;
    }

    std::string BuildRangeStr(int from, int to) {
        std::stringstream ss;
        std::string ret;
        ss << from << "->" << to;
        ss >> ret;
        return ret;
    }

    vector<string> summaryRanges(vector<int>& nums) {
        if (nums.size() <= 0) {
            return std::vector<std::string>();
        }

        int start = nums[0];
        int end = nums[0];

        std::vector<std::string> ans;
        for (int i = 1; i < nums.size(); ++i) {
            int next = nums[i];
            if (end == next - 1) {
                end = next;
            } else {
                if (start == end) {
                    ans.push_back(BuildNumberStr(start));
                } else {
                    ans.push_back(BuildRangeStr(start, end));
                }
                start = end = next;
            }
        }
        if (start == end) {
            ans.push_back(BuildNumberStr(start));
        } else {
            ans.push_back(BuildRangeStr(start, end));
        }

        return ans;
    }
};