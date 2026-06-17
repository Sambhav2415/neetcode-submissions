class StockSpanner {
public:
    stack<int> s;
    StockSpanner() {
        
    }
    
    int next(int price) {
        int ans = 1;
        int len = 1;
        stack<int> e;
        while(!s.empty() ){
            int k = s.top();
            s.pop();
            e.push(k);
            if(k <= price){
                len++;
            }else{
                break;
            }
            ans = max(ans , len);
        }
        while(!e.empty()){
            s.push(e.top());
            e.pop();
        }
        s.push(price);
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */