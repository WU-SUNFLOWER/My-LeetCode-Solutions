class Solution {
public:
    int search(vector<int>& ar, int target) {
        int i = 0;
        int j = ar.size() - 1;
        while (i <= j) {
            int mid = i + ((j - i) >> 1);
            if (ar[mid] == target) {
                return mid;
            }
            else if (ar[mid] < target) {
                i = mid + 1;
            }
            else {
                j = mid - 1;
            }
        }
        return -1;
    }
};