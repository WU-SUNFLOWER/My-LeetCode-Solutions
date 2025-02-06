class Solution {
private:
    int len_;
public:
    int CheckAndCount(const string& s, int l, int r) {
        int cnt = 0;
        while (0 <= l && r < len_ && s[l] == s[r]) {
            ++cnt;
            --l;
            ++r;
        }
        return cnt;
    }

    int countSubstrings(string s) {
        len_ = s.size();
        
        int ans = 0;
        for (int i = 0; i < len_; ++i) {
            ans += CheckAndCount(s, i, i);
            ans += CheckAndCount(s, i, i + 1);
        }
        return ans;
    }
};