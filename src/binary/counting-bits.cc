class Solution {
public:
    int BitCount(int x) {
        int count = 0;
        while (x) {
            count += x % 2;
            x /= 2;
        }
        return count;
    }

    vector<int> countBits(int n) {
        std::vector<int> ans;
        for (int i = 0; i <= n; ++i) {
            ans.push_back(BitCount(i));
        }
        return ans;
    }
};