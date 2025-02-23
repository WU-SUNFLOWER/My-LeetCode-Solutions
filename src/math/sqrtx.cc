class Solution {
public:
    int mySqrt(int x) {
        if (x == 0) return 0;
        if (x == 1) return 1;

        int i = 0;
        int j = x;
        while (i < j) {
            int64_t mid = (i + j) >> 1;
            int64_t mul = mid * mid;
            if (mul == x) {
                return mid;
            }
            else if (mul < x) {
                i = mid + 1;
            }
            else {
                j = mid;
            }
        }
        return i - 1;
    }
};