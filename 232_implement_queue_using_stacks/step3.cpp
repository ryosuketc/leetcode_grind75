
#include <stack>

 class MyQueue2 {
    std::stack<int> stack_in;
    std::stack<int> stack_out;
public:
    MyQueue() {
    }
    
    void push(int x) {
        stack_in.push(x);
    }
    
    int pop() {
        int front = peek();
        stack_out.pop();
        return front;
    }
    
    int peek() {
        if (empty()) {
            throw std::out_of_range("Queue is empty");
        }
        if (stack_out.empty()) {
            while (!stack_in.empty()) {
                stack_out.push(stack_in.top());
                stack_in.pop();
            }
        }
        return stack_out.top();
    }
    
    bool empty() {
        return stack_in.empty() && stack_out.empty();
    }
};

