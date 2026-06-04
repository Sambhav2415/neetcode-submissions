class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        // sort(stones.start() , stones.end());
        priority_queue<int> q(stones.begin(),stones.end());
        while(q.size()>1){
            int x = q.top();
            q.pop();
            int y = q.top();
            q.pop();
            int z = abs(x-y);
            if(z!=0){
                q.push(z);
            }
        }
        if(!q.empty()){
            return q.top();
        }else{
            return 0;
        }
    }
};
