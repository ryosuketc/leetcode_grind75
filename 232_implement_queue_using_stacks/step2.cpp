
// 動かないコード。
// front で状態管理しようとして失敗した。デバッグしようとして面倒になったのでやめた。
#include <stack>

class MyQueue1 {
private:
    std::stack<int> st;
    std::stack<int> st_aux;
    int front;
public:
    MyQueue() {
    }
    
    void push(int x) {
        if (st.empty() && st_aux.empty()) {
            front = x;
        }
        st.push(x);
    }
    
    int pop() {
        if (st.empty() && st_aux.empty()) {
            throw std::out_of_range("Queue is empty");
        }
        if (st_aux.empty()) {
            while (!st.empty()) {
                st_aux.push(st.top());
                st.pop();
            }
        }
        int popped_item = st_aux.top();
        st_aux.pop();
        // Update the front.
        if (!st_aux.empty()) {
            front = st_aux.top();
        }
        return popped_item;
    }
    
    int peek() {
        return front;
    }
    
    bool empty() {
        return st.empty() && st_aux.empty();
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

