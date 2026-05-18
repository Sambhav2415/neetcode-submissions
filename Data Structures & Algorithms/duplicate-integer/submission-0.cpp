class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        set<int> mySet;
        int n = nums.size();
        for(int i=0;i<n;i++){
            mySet.insert(nums[i]);
        }
        if(mySet.size() != n){
            return true;
        }else{
            return false;
        }
    }
};