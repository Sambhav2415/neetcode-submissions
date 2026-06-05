class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = 0;
        for(int num:nums){
            n = num^n;
        }
        return n;
    }
};
