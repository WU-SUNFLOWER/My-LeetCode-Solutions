class Solution {
private:
    std::map<int, int> convert;
public:
    Solution() {
        convert[0] = 0;
        convert[1] = 1;
        convert[6] = 9;
        convert[8] = 8;
        convert[9] = 6;
    }
    int routeNumber(int n) {
        assert(0 <= n && n <= 9);
        auto iter = convert.find(n);
        return (iter == convert.end()) ? -1 : iter->second;
    }
    std::vector<int> splitNumberToVector(int number) {
        std::vector<int> result;
        do {
            result.push_back(number % 10);
            number /= 10;
        } while (number > 0);
        return result;
    }
    int mergeVectorToNumber(std::vector<int>& vec) {
        int result = 0;
        for (auto& digit: vec) {
            result += digit;
            result *= 10;
        }
        return result / 10;
    }
    bool confusingNumber(int n) {
        std::vector original = splitNumberToVector(n);
        std::vector routed = splitNumberToVector(n);
        for (auto& digit: routed) {
            digit = routeNumber(digit);
            if (digit < 0) {
                return false;
            }
        }
        return mergeVectorToNumber(routed) != n;
    }
};