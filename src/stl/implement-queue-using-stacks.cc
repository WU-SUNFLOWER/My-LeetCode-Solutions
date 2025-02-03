class MyQueue {
private:
    std::stack<int> stack_;
    std::stack<int> reversed_stack_;

    void MoveElements() {
        while (!stack_.empty()) {
            int elem = stack_.top();
            stack_.pop();
            reversed_stack_.push(elem);
        }
    }

public:
    MyQueue() {
        
    }
    
    void push(int x) {
        stack_.push(x);
    }
    
    int pop() {
        if (reversed_stack_.empty()) {
            MoveElements();
        }
        int elem = reversed_stack_.top();
        reversed_stack_.pop();
        return elem;
    }
    
    int peek() {
        if (reversed_stack_.empty()) {
            MoveElements();
        }
        return reversed_stack_.top();
    }
    
    bool empty() {
        return stack_.empty() && reversed_stack_.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */