using namespace std;
class MyQueue {
private:
    stack<int> s1; //push stack
    stack<int> s2; //pop stack
    bool push_ ; // if true operation allowed without updating 
    bool pop_ ;
    int num_ele;
public:
    /** Initialize your data structure here. */
    MyQueue() {
        push_ = false;
        pop_ = false;
        num_ele = 0;
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        if( !push_ ){
            update_s1();
        }
        s1.push(x);
        ++num_ele ;
        pop_ = false;
        
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if( !pop_){
            update_s2();
        }
        push_ = false;
        
        int res = s2.top();
        s2.pop();
        --num_ele ;
        return res ;
    }
    
    /** Get the front element. */
    int peek() {
        if( !pop_){
            update_s2();
        }
        push_ = false;
        return s2.top();

    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return (num_ele==0);
    }

private: 
    void update_s1(){
        cout << "update s1"<<endl;
        while(!s1.empty()) s1.pop();
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
        push_ = true;
    }

    void update_s2(){
        cout << "update s2"<<endl;
        while(!s2.empty()) s2.pop();
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        pop_ = true;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * bool param_4 = obj.empty();
 */