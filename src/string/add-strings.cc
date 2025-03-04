class Solution {
public:
    string addStrings(string num1_str, string num2_str) {
        int max_len = std::max(num1_str.size(), num2_str.size());
        std::vector<int> num1(max_len, 0);
        std::vector<int> num2(max_len, 0);

        int i = num1_str.size() - 1;
        int j = max_len - 1;
        while (0 <= i) {
            num1[j] = num1_str[i] - '0';
            --i;
            --j;
        }

        i = num2_str.size() - 1;
        j = max_len - 1;
        while (0 <= i) {
            num2[j] = num2_str[i] - '0';
            --i;
            --j;
        }

        int more = 0;
        std::string str;
        for (int i = max_len - 1; 0 <= i; --i) {
            int sum = num1[i] + num2[i] + more;
            more = sum / 10;
            sum = sum % 10;
            str.insert(str.begin(), sum + '0');
        }
        if (more > 0) {
            str.insert(str.begin(), more + '0');
        }

        return str;
    }
};