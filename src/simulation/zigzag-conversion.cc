class Solution {
public:
    string convert(string s, int numRows) {
        std::vector<std::vector<char>> mat(numRows, std::vector<char>(s.size(), '\0'));

        // Build mat
        int flag = true;
        int i = 0;
        int j = 0;
        for (char ch : s) {
            mat[i][j] = ch;

            if (flag) {
                ++i;
                if (i >= numRows) {
                    flag = false;
                    i = std::max(0, numRows - 2);
                    ++j;
                    if (i == 0) {
                        flag = true;
                    }
                }
            } else {
                --i;
                ++j;
                if (i <= 0) {
                    flag = true;
                }
            }
        }

        // Output mat
        std::string ret;
        for (int i = 0; i < numRows; ++i) {
            for (int j = 0; j < s.size(); ++j) {
                if (mat[i][j] != '\0') {
                    ret.push_back(mat[i][j]);
                }
            }
        }

        return ret;
    }
};