class Solution {
public:
    int quick1(vector<int>& nums,int low,int high){
        int pivot = nums[high];
        int i=low-1;
        for(int j=low;j<high;j++){
            if(nums[j]<=pivot){
                i++;
                swap(nums[i],nums[j]);
            }
        }
        i++;
        swap(nums[i],nums[high]);
        return i;
    }
    void quick2(vector<int>& nums,int low,int high){
        if(low >= high){
            return ;
        }
        int p = quick1(nums,low,high);
        quick2(nums,low,p-1);
        quick2(nums,p+1,high);
    }
    void sortColors(vector<int>& nums) {
        quick2(nums,0,nums.size()-1);
    }
};