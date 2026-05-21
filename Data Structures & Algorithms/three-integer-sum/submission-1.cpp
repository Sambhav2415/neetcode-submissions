class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        vector<vector<int>> ans;
        for(int i=0;i<n;i++){
            if(i!=0 && nums[i]==nums[i-1]){
                continue;
            }
            int st = i+1;
            int end = n-1;
            while(st < end){
                int sum = nums[i] + nums[st] + nums[end];
                if(sum == 0){
                    ans.push_back({nums[i],nums[st],nums[end]});
                    int oldSt = st;
                    int oldEnd = end;
                    while(st < end && nums[oldSt]==nums[st]) st++;
                    while(st < end && nums[oldEnd]==nums[end]) end--;
                }else if(sum >0){
                    end--;
                }else{
                    st++;
                }
            }
        }
        return ans;
    }
};
