class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int,char>>pq;
        if(a>0) pq.push({a,'a'});
        if(b>0) pq.push({b,'b'});
        if(c>0) pq.push({c,'c'});
        string s = "";
        while(!pq.empty()){
            auto [val,alp] = pq.top();
            pq.pop();
            int k = s.size();
            if(k < 2){
                s += alp;
                val--;
            }else {
                if(s[k-1] == alp && s[k-2] == alp){
                    if(pq.empty()){
                        return s;
                    }
                    auto [val1,alp1] = pq.top();
                    pq.pop();
                    s += alp1;
                    val1--;
                    if(val1 >0) pq.push({val1,alp1});
                }else{
                    s += alp;
                    val--;
                }
                
            }
            if(val >0) pq.push({val,alp});
        }
        return s;
    }
};