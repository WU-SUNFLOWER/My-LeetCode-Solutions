class Solution {
public:
    int countElements(vector<int>& arr) {
        std::set<int> myset;
        for (int num: arr) {
            myset.insert(num);
        }
        int ans = 0;
        for (int num: arr) {
            if (myset.find(num + 1) != myset.end()) {
                ++ans;
            }
        }
        return ans;
    }
};