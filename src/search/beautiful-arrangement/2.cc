class Solution {
private:
    std::vector<int> values_;

public:
    int Solve(int pos, int n) {
        if (pos > n) {
            return 1;
        }

        int cnt = 0;
        for (int i = pos; i <= n; ++i) {
            if (values_[i] % pos == 0 || pos % values_[i] == 0) {
                std::swap(values_[pos], values_[i]);
                cnt += Solve(pos + 1, n);
                std::swap(values_[pos], values_[i]);
            }
        }
        return cnt;
    }

    int countArrangement(int n) {
        values_ = std::vector<int>(n + 1);
        for (int i = 1; i <= n; ++i) {
            values_[i] = i;
        }
        return Solve(1, n);
    }
};