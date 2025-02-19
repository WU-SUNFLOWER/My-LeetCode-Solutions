class Solution {
public:
    bool isHappy(int n) {
        std::unordered_set<int> vis;
        int sum = n;
        while (sum != 1) {
            int cur = sum;
            sum = 0;
            while (cur > 0) {
                int tmp = cur % 10;
                sum += tmp * tmp;
                cur /= 10;
            }
            if (vis.contains(sum)) {
                return false;
            }
            vis.insert(sum);
        }
        return true;
    }
};