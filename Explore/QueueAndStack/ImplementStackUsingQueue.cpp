class MyStack {
private:
    queue<int> q1; //push queue
    queue<int> q2;// pop queue
    bool q1_valid;
    int num_ele;
public:
    /** Initialize your data structure here. */
    MyStack() {
        num_ele = 0;
        q1_valid = true;
        //can_pop = false;
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        if(q1_valid){
            q1.push(x);
        }else{
            q2.push(x);
        }
        num_ele++;
        
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() { //after pop / top, valid needs to be changed
        int res;
        if(q1_valid){// 
            for(int i = 0; i < num_ele-1; i++){
                q2.push(q1.front());
                q1.pop();
            }
            res = q1.front();
            q1.pop();
            q1_valid = false;
            
            
        }else{
            for(int i = 0; i < num_ele-1; i++){
                q1.push(q2.front());
                q2.pop();
            }
            res = q2.front();
            q2.pop();
            q1_valid = true;
            
        }
        num_ele--;
        return res;
    }
    
    /** Get the top element. */
    int top() {
        int res;
        if(q1_valid){// 
            for(int i = 0; i < num_ele-1; i++){
                q2.push(q1.front());
                q1.pop();
            }
            res = q1.front();
            q1.pop();
            q2.push(res);
            q1_valid = false;
            
        }else{
            for(int i = 0; i < num_ele-1; i++){
                q1.push(q2.front());
                q2.pop();
            }
            res = q2.front();
            q2.pop();
            q1.push(res);
            q1_valid = true;
            
        }
        return res;
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return (num_ele==0);
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = new MyStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * bool param_4 = obj.empty();
 */