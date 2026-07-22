class MyCircularQueue {
public:
    vector<int> vec;
    int front;
    int rear;
    int count;
    int capacity;
    MyCircularQueue(int k) {
        capacity = k;
        front = 0;
        rear = 0;
        count =0;
        vec.assign(k,0);
    }
    
    bool enQueue(int value) {
        if(count >= capacity){
            return false;
        }
        count++;
        vec[rear] = value;
        rear = (rear+1)%capacity;
        return true;
    }
    
    bool deQueue() {
        if(count == 0){
            return false;
        }
        count--;
        front = (front+1)%capacity;
        return true;
    }
    
    int Front() {
        if(count ==0){
            return -1;
        }
        return vec[front];
    }
    
    int Rear() {
        if(count ==0){
            return -1;
        }
        int k = (rear-1+capacity)%capacity;
        return vec[k];
    }
    
    bool isEmpty() {
        if(count ==0){
            return true;
        }
        return false;
    }
    
    bool isFull() {
        if(count == capacity){
            return true;
        }
        return false;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */