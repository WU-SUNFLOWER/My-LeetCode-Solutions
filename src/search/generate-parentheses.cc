class Solution {
private:
    std::vector<string> solutions_;
public:

    void DFS(std::string& cur_str, int last_n, int balance) {
        if (last_n == 0) {
            solutions_.push_back(cur_str);
            return;
        }
        if (balance > 0) {
            cur_str.push_back(')');
            DFS(cur_str, last_n - 1, balance - 1);
            cur_str.pop_back();
        }
        if (balance < last_n) {
            cur_str.push_back('(');
            DFS(cur_str, last_n, balance + 1);
            cur_str.pop_back();            
        }
    }

    vector<string> generateParenthesis(int n) {
        std::string str;
        DFS(str, n, 0);
        return solutions_;
    }
};