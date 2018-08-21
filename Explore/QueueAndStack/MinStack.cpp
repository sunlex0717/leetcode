class MinStack {
private:
    stack<int> stack1;
    stack<int> stack2;
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        if( stack1.empty() || x <= getMin() ){
            stack1.push(x);
        }else{
            stack2.push(x);
        }
    }
    
    void pop() {
        if(stack1.top() == )
    }
    
    int top() {
        
    }
    
    int getMin() {
        return stack1.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */