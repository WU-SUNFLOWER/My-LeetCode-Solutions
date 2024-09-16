class Solution {
public:
    bool isArmstrong(int n) {
        std::vector<int> digits;
        int digit_size = 0;
        int temp = n;
        do {
            digits.push_back(temp % 10);
            temp /= 10;
            ++digit_size;
        } while (temp > 0);
        int sum = 0;
        for (int digit: digits) {
            sum += std::pow(digit, digit_size);
        }
        return sum == n;
    }
};