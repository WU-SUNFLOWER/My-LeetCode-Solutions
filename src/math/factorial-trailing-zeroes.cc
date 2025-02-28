class Solution {
public:
    int trailingZeroes(int n) {
        int two_cnt = 0;
        int five_cnt = 0;

        for (int i = 1; i <= n; ++i) {
            int ii = i;
            while (ii % 5 == 0) {
                ii /= 5;
                ++five_cnt;
            }

            ii = i;
            while (ii % 2 == 0) {
                ii /= 2;
                ++two_cnt;
            }
        }

        return std::min(two_cnt, five_cnt);
    }
};