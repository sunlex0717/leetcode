using namespace std;
class MyCircularQueue {
private:
    int size_;
    int num_ele;
    int start_pointer;
    int end_pointer;
    vector<int> circular_queue;
public:
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k) {
        num_ele = 0;
        start_pointer = -1;
        end_pointer = -1;
        size_ = k;
        circular_queue.resize(k);
    }
    
    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        if(isFull()){
            cout<<"queue is full, cannot do enqueue"<<endl;
            return false;
        }
        if(isEmpty()){
            start_pointer = 0;
        }
        end_pointer = (end_pointer+1) % size_;
        circular_queue[end_pointer] = value;
        num_ele++;
        return true;
        
    }
    
    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        if(isEmpty()){
            return false;
        }

        if (start_pointer == end_pointer) {
            start_pointer = -1;
            end_pointer = -1;
            num_ele--;
            return true;
        }
        
        start_pointer = (start_pointer+1) % size_;
        num_ele--;
        return true;
        
    }
    
    /** Get the front item from the queue. */
    int Front() {
        if(isEmpty()){
            return -1;
        }
        return circular_queue[start_pointer];
    }
    
    /** Get the last item from the queue. */
    int Rear() {
        if(isEmpty()){
            return -1;
        }
        return circular_queue[end_pointer];
    }
    
    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        if(num_ele == 0){
            return true;
        }else{
            return false;
        }
        
    }
    
    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        if(num_ele == size_){
            return true;
        }else{
            return false;
        }
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue obj = new MyCircularQueue(k);
 * bool param_1 = obj.enQueue(value);
 * bool param_2 = obj.deQueue();
 * int param_3 = obj.Front();
 * int param_4 = obj.Rear();
 * bool param_5 = obj.isEmpty();
 * bool param_6 = obj.isFull();
 */