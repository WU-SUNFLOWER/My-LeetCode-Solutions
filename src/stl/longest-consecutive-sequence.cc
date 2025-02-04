class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        std::unordered_set<int> my_set(nums.begin(), nums.end());
        int answer = 0;
        while (!my_set.empty()) {
            int cur = *(my_set.begin());
            my_set.erase(cur);

            int l = cur - 1;
            int r = cur + 1;
            while (my_set.contains(l)) {
                my_set.erase(l--);
            }
            while (my_set.contains(r)) {
                my_set.erase(r++);
            }

            answer = std::max(answer, (r - 1) - (l + 1) + 1);
        }
        return answer;
    }
};