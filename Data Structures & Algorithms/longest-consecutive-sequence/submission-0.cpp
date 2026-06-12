class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(),nums.end());
        int ans = 0;
        for(int num : s){
            if(!s.count(num-1)){
                int curr = num+1;
                int len = 1;
                while(s.count(curr)){
                    curr++;
                    len++;
                }
                ans = max(len,ans);
            }
        }
        return ans;
    }
};
