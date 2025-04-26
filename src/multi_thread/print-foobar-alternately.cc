#include <semaphore.h>

class FooBar {
private:
    int n;
    sem_t foo_printed_;
    sem_t bar_printed_;

public:
    FooBar(int n) {
        this->n = n;
        sem_init(&foo_printed_, 0, 0);
        sem_init(&bar_printed_, 0, 1);
    }

    void foo(function<void()> printFoo) {
        
        for (int i = 0; i < n; i++) {
            sem_wait(&bar_printed_);
        	// printFoo() outputs "foo". Do not change or remove this line.
        	printFoo();
            sem_post(&foo_printed_);
        }
    }

    void bar(function<void()> printBar) {
        
        for (int i = 0; i < n; i++) {
            sem_wait(&foo_printed_);
        	// printBar() outputs "bar". Do not change or remove this line.
        	printBar();
            sem_post(&bar_printed_);
        }
    }
};