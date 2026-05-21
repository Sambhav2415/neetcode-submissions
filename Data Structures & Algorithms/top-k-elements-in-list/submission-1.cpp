class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int p) {
        unordered_map<int , int> m;
        for(int s : nums){
            if(m.count(s)){
                m[s]++;
            }else{
                m[s] = 1;
            }
        }
        priority_queue<pair<int,int>> pq;
        for(auto &pai:m){
            pq.push(make_pair(pai.second , pai.first));
        }

        vector<int> vec;
        int k = 1;
        while(!pq.empty()){
            if(k++ > p){
                return vec;
            }
            vec.push_back(pq.top().second);
            pq.pop();
        }
        return vec;
    }
};
