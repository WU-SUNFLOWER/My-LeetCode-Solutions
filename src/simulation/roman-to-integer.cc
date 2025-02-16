class Solution {
private:
    std::unordered_map<char, int> char_int_map_ = {
        { 'I', 1    },
        { 'V', 5    },
        { 'X', 10   },
        { 'L', 50   },
        { 'C', 100  },
        { 'D', 500  },
        { 'M', 1000 },
    };

public:
    int romanToInt(string s) {
        int sum = 0;
        int len = s.size();
        int i = 0;
        while (i < len) {
            char cur_ch = s[i];
            int cur_num = char_int_map_[cur_ch];
            if (i < len - 1) {
                char next_ch = s[i + 1];
                int next_num = char_int_map_[next_ch];
                /*
                I 可以放在 V (5) 和 X (10) 的左边，来表示 4 和 9。
                X 可以放在 L (50) 和 C (100) 的左边，来表示 40 和 90。 
                C 可以放在 D (500) 和 M (1000) 的左边，来表示 400 和 900。
                */
                if (cur_ch == 'I' && (next_ch == 'V' || next_ch == 'X')
                    || cur_ch == 'X' && (next_ch == 'L' || next_ch == 'C')
                    || cur_ch == 'C' && (next_ch == 'D' || next_ch == 'M')) 
                {
                    sum += next_num - cur_num;
                    i += 2;
                    continue;
                }
            }
            sum += cur_num;
            i += 1;
        }
        return sum;
    }
};