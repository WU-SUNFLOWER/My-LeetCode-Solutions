class Solution {
private:
    std::vector<std::string> answers_;

public:
    bool CanInsertDot(const std::string& s, int start, int length) {
        switch (length) {
            case 1:
                return true;
            case 2: {
                int num = std::stoi(s.substr(start, length));
                return 10 <= num && num <= 99;                
            }
            case 3: {
                int num = std::stoi(s.substr(start, length));
                return 100 <= num && num <= 255;                
            }
            default:
                return false;
        }
    }

    void DumpAnswer(const std::string& s, std::vector<int>& dots) {
        assert(dots.size() == 3);
        std::string s1 = s.substr(0, dots[0]);
        std::string s2 = s.substr(dots[0], dots[1] - dots[0]);
        std::string s3 = s.substr(dots[1], dots[2] - dots[1]);
        std::string s4 = s.substr(dots[2]);
        answers_.push_back(s1 + "." + s2 + "." + s3 + "." + s4);
    }

    // [low, high)
    void Insert(const std::string& s, std::vector<int>& dots, int low, int high, int chance) {
        // 三次插点机会用光以后，还要检查一下尾巴是不是合法的
        if (chance == 0) {
            if (CanInsertDot(s, low, high - low)) {
                DumpAnswer(s, dots);
            }
            return;
        }
        
        // 探测靠左侧可以插入点号的地方
        for (int len = 1; len <= 3 && low + len <= high; ++len) {
            if (CanInsertDot(s, low, len)) {
                dots.push_back(low + len);
                Insert(s, dots, low + len, high, chance - 1);
                dots.pop_back();
            }
        }
    }

    vector<string> restoreIpAddresses(string s) {
        std::vector<int> dots;
        Insert(s, dots, 0, s.size(), 3);
        return answers_;
    }
};