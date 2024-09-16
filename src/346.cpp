class MovingAverage {
private:
    const int capacity = 0;
    int pos = 0;
    int size = 0;
    int* buffer = nullptr;
public:
    MovingAverage(int cap) : capacity(cap) {
        this->buffer = new int[cap];
    }
    ~MovingAverage() {
        delete[] this->buffer;
    }
    double next(int val) {
        buffer[pos] = val;
        pos = (pos + 1) % capacity;
        size = std::min(size + 1, capacity);
        double ans = 0;
        for (int i = 0; i < size; ++i) {
            ans += buffer[i];
        }
        return ans / size;
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */