class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int,int>> pq;
        vector<int> ans;
        for(int i=0;i<k;i++){
            pq.push({nums[i],i});
        }
        ans.push_back(pq.top().first);

        for(int i=k;i<nums.size();i++){
            int idx = i-k+1;
            while(!pq.empty() && pq.top().second < idx){
                pq.pop();
            }
            pq.push({nums[i],i});
            ans.push_back(pq.top().first);
        }

        return ans;
    }
};
