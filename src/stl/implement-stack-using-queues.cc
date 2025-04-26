class MyStack {
private:
    bool is_changed_ { false };
    std::queue<int>* queue_1;
    std::queue<int>* queue_2;
public:
    MyStack() {
        queue_1 = new std::queue<int>();
        queue_2 = new std::queue<int>();
    }

    void push(int x) {
        queue_1->push(x);
    }
    
    int pop() {
        while (queue_1->size() > 1) {
            int temp = queue_1->front();
            queue_1->pop();
            queue_2->push(temp);
        }

        int result = queue_1->front();
        queue_1->pop();

        std::swap(queue_1, queue_2);

        return result;
    }
    
    int top() {
        int result;
        while (queue_1->size() > 0) {
            result = queue_1->front();
            queue_1->pop();
            queue_2->push(result);
        }

        std::swap(queue_1, queue_2);

        return result;
    }
    
    bool empty() {
        return queue_1->empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */