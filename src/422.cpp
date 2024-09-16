#define N 500

class Solution {
private:
    int rows;
    int cols;
    char matrix[N][N];
public:
    bool validWordSquare(vector<string>& words) {
        rows = words.size();
        cols = 0;
        // build matrix
        memset(matrix, 0, sizeof(matrix));
        for (int i = 0; i < words.size(); ++i) {
            std::string& word = words[i];
            int wordLength = word.length();
            cols = std::max(cols, wordLength);
            for (int j = 0; j < wordLength; ++j) {
                matrix[i][j] = word[j];
            }
        }
        // check
        int limit = std::max(rows, cols);
        for (int k = 0; k < limit; ++k) {
            for (int i = 0; i < limit; ++i) {
                if (matrix[k][i] != matrix[i][k]) {
                    return false;
                }
            }
        }
        return true;
    }
};