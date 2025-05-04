class Solution {
private:
    void SinkDown(std::vector<int>& arr, int arr_size, int i) {
        int limit = arr_size / 2 - 1;
        while (i <= limit) {
            int lchild = i * 2 + 1;
            int rchild = i * 2 + 2;

            int min_child = i;
            if (lchild < arr_size && arr[min_child] > arr[lchild]) {
                min_child = lchild;
            }
            if (rchild < arr_size && arr[min_child] > arr[rchild]) {
                min_child = rchild;
            }

            if (min_child == i) {
                break;
            }

            std::swap(arr[i], arr[min_child]);
            i = min_child;
        }
    }

    void Heapify(std::vector<int>& arr) {
        int i = arr.size() / 2 - 1;
        while (0 <= i) {
            int lchild = i * 2 + 1;
            int rchild = i * 2 + 2;
            
            int min_child = i;
            if (lchild < arr.size() && arr[min_child] > arr[lchild]) {
                min_child = lchild;
            }
            if (rchild < arr.size() && arr[min_child] > arr[rchild]) {
                min_child = rchild;
            }

            if (i != min_child) {
                std::swap(arr[i], arr[min_child]);
                SinkDown(arr, arr.size(), min_child);
            }

            --i;
        }
    }

public:
    vector<int> inventoryManagement(vector<int>& stock, int cnt) {
        Heapify(stock);

        int last_pos = stock.size() - 1;
        while (0 <= last_pos && 0 < cnt) {
            std::swap(stock[0], stock[last_pos]);
            SinkDown(stock, last_pos, 0);
            --last_pos;
            --cnt;
        }

        return std::vector<int>(stock.begin() + last_pos + 1, stock.end());
    }
};