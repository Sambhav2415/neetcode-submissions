class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        vector<vector<int>> ans;
        for(int j=0;j<n;j++){
            if(j != 0 && nums[j] == nums[j-1]){
                continue;
            }
            for(int i=j+1;i<n;i++){
                if(i!=j+1 && nums[i]==nums[i-1]){
                    continue;
                }
                int st = i+1;
                int end = n-1;
                while(st < end){
                    long long sum = (long long)nums[j]+nums[i]+nums[st]+nums[end];
                    if(sum == target){
                        ans.push_back({nums[j],nums[i],nums[st],nums[end]});
                        int oldSt = st;
                        int oldEnd = end;
                        while(st < end && nums[oldSt]==nums[st]) st++;
                        while(st < end && nums[oldEnd]==nums[end]) end--;
                    }else if(sum >target){
                        end--;
                    }else{
                        st++;
                    }
                }
            }
        }
        return ans;
    }
};