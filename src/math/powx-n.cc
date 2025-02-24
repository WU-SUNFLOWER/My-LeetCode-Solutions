class Solution {
public:
    double Pow(double x, int64_t n) {
        if (n == 0) {
            return 1.0;
        }
        if (n == 1) {
            return x;
        }
        double part = myPow(x, n / 2);
        double tmp = n % 2 ? x : 1.0;
        return part * part * tmp;
    }

    double myPow(double x, int n) {
        int64_t nn = n;
        return nn < 0 ? (1.0 / Pow(x, -nn)) : Pow(x, nn);
    }
};