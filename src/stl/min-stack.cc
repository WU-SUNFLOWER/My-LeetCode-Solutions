class MinStack {
private:
    std::stack<int> stack_;
    std::stack<int> special_stack_;

public:
    MinStack() {
        
    }
    
    void push(int val) {
        stack_.push(val);
        if (special_stack_.empty()) {
            special_stack_.push(val);
        } else {
            special_stack_.push(std::min(val, special_stack_.top()));
        }
    }
    
    void pop() {
        if (stack_.empty()) {
            assert(special_stack_.empty());
            return;
        }
        stack_.pop();
        special_stack_.pop();
    }
    
    int top() {
        return stack_.top();
    }
    
    int getMin() {
        return special_stack_.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */