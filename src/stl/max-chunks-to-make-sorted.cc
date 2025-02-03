class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int chunks = 0, cur_max = 0;
        for (int i = 0; i < arr.size(); ++i) {
            cur_max = max(cur_max, arr[i]);
            chunks += cur_max == i;
        }
        return chunks;
    }
};