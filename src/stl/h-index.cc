class Solution {
public:
    int hIndex(vector<int>& citations) {
        // counter[ref_cnt] 引用次数为ref_cnt的论文有多少篇
        std::unordered_map<int, int> counter;
        // 最大的引用次数是多少
        int max_ref_cnt = 0;
        for (int ref_cnt : citations) {
            max_ref_cnt = std::max(max_ref_cnt, ref_cnt);
            ++counter[ref_cnt];
        }

        int total_citation = 0;
        for (int h = max_ref_cnt; h > 0 ; --h) {
            // 统计有多少篇论文的被引用次数大于等于h
            total_citation += counter[h];
            // 如果被引用次数大于等于h的论文，至少有h篇，那么就返回结果
            if (total_citation >= h) {
                return h;
            }
        }

        return 0;
    }
};