class Solution {
public:
    void RemoveExtraSpaces(std::string& s) {
        int slow = 0;
        int fast = 0;

        // 剔除头部空格
        while (s[fast] == ' ') ++fast;

        int flag = false;  // 是否在之前已经遇到过空格了
        while (fast < s.size()) {
            if (s[fast] != ' ') {
                flag = false;
                s[slow++] = s[fast++];
            }
            // 之前已经遇到过空格了
            else if (flag) {
                ++fast;
            }
            // 之前没有遇到空格
            else {
                flag = true;
                s[slow++] = s[fast++];
            }
        }

        // 剔除尾部空格
        s.resize(slow);
        if (s.back() == ' ') {
            s.pop_back();
        }
    }

    void ReverseSingleWord(std::string& s, int start, int end) {
        for (; start < end; ++start, --end) {
            std::swap(s[start], s[end]);
        }
    }

    string reverseWords(string s) {
        // 1. 删除多余空格
        RemoveExtraSpaces(s);

        // 2. 整体翻转字符串
        std::reverse(s.begin(), s.end());
        
        // 3. 局部翻转每个单词
        int i = 0;  // i用于探测单个单词的结尾
        int j = 0;  // j用于锚定单个单词的开始位置
        while (i < s.size()) {
            if (s[i] == ' ') {
                // 局部翻转单词
                ReverseSingleWord(s, j, i - 1);
                // 更新指针
                i += 1;
                j = i;
            } else {
                i += 1;
            }
        }
        ReverseSingleWord(s, j, i - 1);

        return s;
    }
};