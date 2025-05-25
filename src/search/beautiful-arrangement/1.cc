class Solution {
private:
    std::unordered_set<int> visited_;

public:
    int Solve(int i, int n) {
        if (i > n) {
            return 1;
        }

        int cnt = 0;
        for (int num = 1; num <= n; ++num) {
            if (visited_.contains(num)) {
                continue;
            }
            // num能作为perm[i]吗？
            if (num % i == 0 || i % num == 0) {
                visited_.insert(num);
                cnt += Solve(i + 1, n);
                visited_.erase(num);
            }
        }
        return cnt;
    }

    int countArrangement(int n) {
        return Solve(1, n);
    }
};