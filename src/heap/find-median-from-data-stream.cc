class MedianFinder {
private:
    std::priority_queue<int, std::vector<int>, std::less<int>> left_;  // 大顶堆
    std::priority_queue<int, std::vector<int>, std::greater<int>> right_;  // 小顶堆 

public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if (left_.empty() || num <= left_.top()) {
            left_.push(num);
            // 不需要调整：
            // left_.size() == right_.size()
            // left_.size() == right_.size() + 1
            // 需要调整：
            // left_.size() > right_.size() + 1
            if (left_.size() > right_.size() + 1) {
                right_.push(left_.top());
                left_.pop();
            }
        } else {
            right_.push(num);
            // 不需要调整：
            // right_.size() == left_.size()
            // right_.size() + 1 == left_.size()
            if (right_.size() > left_.size()) {
                left_.push(right_.top());
                right_.pop();
            }
        }
    }
    
    double findMedian() {
        if (left_.size() > right_.size()) {
            return left_.top();
        } else {
            return (left_.top() + right_.top()) / 2.0;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */