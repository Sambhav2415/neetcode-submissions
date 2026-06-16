class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        mp[0] = 1;
        int seq = 0;
        int ans = 0;
        for(int num:nums){
            seq += num;
            int toFind = seq-k;
            if(mp.count(toFind)){
                ans += mp[toFind];
            }
            if(mp.count(seq)){
                mp[seq]++;
            }else{
                mp[seq] = 1;
            }
        }
        return ans;
    }
};