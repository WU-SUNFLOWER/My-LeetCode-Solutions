class Solution {
public:
    bool judgeSquareSum(int c) {
        std::unordered_set<double> my_set;
        for (double a = 0; a <= std::sqrt(c); ++a) {
            double b = std::sqrt(c - a * a);
            my_set.insert(a);
            if (my_set.contains(b)) {
                return true;
            }
        }
        return false;
    }
};