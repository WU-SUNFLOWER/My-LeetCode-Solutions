class Solution {
public:
    vector<int> partitionLabels(string s) {
        std::unordered_map<char, int> appear_last;
        for (int i = 0; i < s.size(); ++i) {
            appear_last[s[i]] = i;
        }

        int last_pos = -1;
        int partition_end = 0;
        std::vector<int> ans;
        for (int i = 0; i < s.size(); ++i) {
            partition_end = std::max(partition_end, appear_last[s[i]]);
            if (partition_end == i) {
                ans.push_back(i - last_pos);
                last_pos = i;
            }
        }
        return ans;
    }
};