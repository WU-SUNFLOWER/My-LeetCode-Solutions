class Solution {
public:
    int strStr(string haystack, string needle) {
        auto ret = haystack.find(needle);
        if (ret == std::string::npos) {
            return -1;
        } else {
            return ret;
        }
    }
};