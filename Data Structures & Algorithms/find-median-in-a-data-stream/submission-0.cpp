class MedianFinder {
public:
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        int n = minHeap.size();
        int m = maxHeap.size();
        if(m ==0 && n == 0){
            maxHeap.push(num);
        }else if(m == 0 && n == 1){
            int top = minHeap.top();
            if(num > top){
                minHeap.push(num);
            }else{
                maxHeap.push(num);
            }
        }else if(m == 1 && n == 0){
            int top = maxHeap.top();
            if(num < top){
                maxHeap.push(num);
            }else{
                minHeap.push(num);
            }
        }else{
            int topMin = minHeap.top();
            int topMax = maxHeap.top();
            if(num > topMin){
                minHeap.push(num);
            }else{
                maxHeap.push(num);
            }
        }
        n = minHeap.size();
        m = maxHeap.size();
        if(abs(n-m) > 1){
            if(n-m > 1){
                maxHeap.push(minHeap.top());
                minHeap.pop();
            }else{
                minHeap.push(maxHeap.top());
                maxHeap.pop();
            }
        }
    }
    
    double findMedian() {
        int n = minHeap.size();
        int m = maxHeap.size();
        if((n+m)%2==0){
            return ((long long)minHeap.top() + maxHeap.top()) / 2.0;
        }else{
            if(n-m == 1){
                return minHeap.top();
            }else{
                return maxHeap.top();
            }
        }
    }
};
