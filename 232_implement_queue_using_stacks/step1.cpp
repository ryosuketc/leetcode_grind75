class MyQueue {
private:
    // stack holds items in quque fashion.
    std::stack<int> st;
    std::stack<int> st_aux;
public:
    MyQueue() {
    }
    
    void push(int x) {
        if (st.empty()) {
            st.push(x);
            return;
        }
        while (!st.empty()) {
            st_aux.push(st.top());
            st.pop();
        }
        st_aux.push(x);
        while (!st_aux.empty()) {
            st.push(st_aux.top());
            st_aux.pop();
        }
    }
    
    int pop() {
        if (st.empty()) {
            throw std::out_of_range("Queue is empty");
        }
        int top = st.top();
        st.pop();
        return top;
    }
    
    int peek() {
        if (st.empty()) {
            throw std::out_of_range("Queue is empty");
        }
        return st.top();
    }
    
    bool empty() {
        return st.empty();
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
