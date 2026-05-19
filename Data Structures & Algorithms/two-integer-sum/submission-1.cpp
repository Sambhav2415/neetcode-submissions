class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int end = nums.size()-1;
        unordered_map<int,int> m;
        for(int i=0;i<=end;i++){
            int find = target - nums[i];
            if(m.count(find)){
                return {m[find],i};
            }else{
                if(!m.count(nums[i])){
                    m[nums[i]] = i;
                }else{
                    continue;
                }
            }
        }
        return {};
    }
};
