class Solution {
public:
    bool judgeSquareSum(uint64_t c) {
        uint64_t i = 0;
        uint64_t j = static_cast<uint64_t>(std::sqrt(c)) + 1;
        while (i <= j) {
            uint64_t cur = i * i + j * j;
            if (cur == c) {
                return true;
            }
            if (cur < c) {
                ++i;
            } else {
                --j;
            }
        }
        return false;
    }
};