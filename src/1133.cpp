class Solution {
private:
    int mycount[1001];
public:
    int largestUniqueNumber(vector<int>& nums) {
        memset(mycount, 0, sizeof(mycount));
        for (int num: nums) {
            ++mycount[num];
        }
        int ans = -1;
        for (int i = 0; i < sizeof(mycount) / sizeof(int); ++i) {
            if (mycount[i] == 1) {
                ans = i;
            }
        }
        return ans;
    }
};