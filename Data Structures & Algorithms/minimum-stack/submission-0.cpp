class MinStack {
private:
    stack<int> main_stk;
    stack<int> prefix_stk;
public:
    MinStack() {
        stack<int> main_stk;
        stack<int> prefix_stk;
    }
    
    void push(int val) {
        main_stk.push(val);
        if (prefix_stk.empty()) {
            prefix_stk.push(val);
        } else {
            prefix_stk.push(min(prefix_stk.top(), val));
        }
    }
    
    void pop() {
        main_stk.pop();
        prefix_stk.pop();
    }
    
    int top() {
        return main_stk.top();
    }
    
    int getMin() {
        return prefix_stk.top();
    }
};
