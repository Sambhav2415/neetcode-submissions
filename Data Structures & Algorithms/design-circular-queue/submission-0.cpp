class MyCircularQueue {
public:
    vector<int> vec;
    int front;
    int rear;
    int count;
    int capacity;
    MyCircularQueue(int k) {
        vec.resize(k);
        front =0;
        rear =0;
        count=0;
        capacity = k;
    }
    
    bool enQueue(int value) {
        if(count == capacity){
            return false;
        }
        count++;
        vec[rear] = value;
        rear = (rear + 1) % capacity;
        return true;
    }
    
    bool deQueue() {
        if(count <= 0){
            return false;
        }
        front = (front + 1) % capacity;
        count--;
        return true;
    }
    
    int Front() {
        if (isEmpty()) return -1;
        return vec[front];
    }
    
    int Rear() {
        if (isEmpty()) return -1;
        return vec[(rear - 1 + capacity) % capacity];
    }
    
    bool isEmpty() {
        if(count == 0){
            return true;
        }else{
            return false;
        }
    }
    
    bool isFull() {
        if(count == capacity){
            return true;
        }else{
            return false;
        }
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