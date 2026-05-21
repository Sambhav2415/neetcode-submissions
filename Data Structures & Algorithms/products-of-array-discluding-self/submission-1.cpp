class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int prod = 1;
        bool firstZero = false;
        bool secondZero = false;
        if(nums[0]==0){
            firstZero = true;
        }
        int n = nums.size();
        for(int i=1;i<n;i++){
            if(nums[i] == 0){
                if(!firstZero){
                    firstZero = true;
                }else{
                    secondZero = true;
                    break;
                }
            }else{
                prod *= nums[i];
            }
        }

        vector<int> array(n,1);
        
        if(nums[0] == 0){
            if(secondZero){
                array[0] = 0;
            }else if(firstZero){
                array[0] = prod;
            }
        }else{
            if(firstZero){
                array[0] = 0;
            }else{
                array[0] = prod;
            }
        }

        for(int i=1;i<n;i++){
            if(nums[i] == 0){
                if(secondZero){
                    array[i] = 0;
                }else{
                    array[i] = prod*nums[0];
                }
            }else{
                if(firstZero){
                    array[i] = 0;
                }else{
                    array[i] = prod/nums[i];
                    array[i] *= nums[0];
                }
            }
        }
        return array;
    }
};
