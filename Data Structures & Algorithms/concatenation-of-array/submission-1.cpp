class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int n = nums.size();
        int size = 2*n;
        vector<int> vec(size,0);
        for(int i=0;i<n;i++){
            vec[i] = nums[i];
            vec[i+n] = nums[i];
        }
        return vec;
    }
};