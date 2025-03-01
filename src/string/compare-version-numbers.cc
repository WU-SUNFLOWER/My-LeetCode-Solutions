class Solution {
public:
    std::vector<int> SplitVersion(std::string& version) {
        int i = 0;
        int start = 0;
        std::vector<int> ret;
        for (; i < version.size(); ++i) {
            if (version[i] == '.') {
                ret.emplace_back(std::stoi(version.substr(start, i - start)));
                start = i + 1;
            }
        }
        ret.emplace_back(std::stoi(version.substr(start, i - start)));

        return ret;
    }

    int compareVersion(string version1, string version2) {
        auto splited_1 = SplitVersion(version1);
        auto splited_2 = SplitVersion(version2);

        // 填充
        int max_len = std::max(splited_1.size(), splited_2.size());
        while (splited_1.size() < max_len) {
            splited_1.emplace_back(0);
        }
        while (splited_2.size() < max_len) {
            splited_2.emplace_back(0);
        }

        // 比较
        for (int i = 0; i < splited_1.size(); ++i) {
            if (splited_1[i] > splited_2[i]) {
                return 1;
            }
            if (splited_1[i] < splited_2[i]) {
                return -1;
            }
        }

        return 0;
    }
};