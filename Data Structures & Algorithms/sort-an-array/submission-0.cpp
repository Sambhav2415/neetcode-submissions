class Solution {
public:
    void merge(vector<int>& nums,int st,int end,int mid){
        vector<int> left(mid-st+2);
        vector<int> right(end-mid+1);
        left[mid-st+1] = INT_MAX;
        right[end-mid]  = INT_MAX;
        int j=0;
        for(int i=st;i<=mid;i++){
            left[j++] = nums[i];
        } 
        j=0;
        for(int i=mid+1;i<=end;i++){
            right[j++]=nums[i];
        }
        int l=0,r=0;
        for(int i=st;i<=end;i++){
            if(left[l]<=right[r]){
                nums[i] = left[l++];
            }else{
                nums[i] = right[r++];
            }
        }
    }

    void merge2(vector<int>& nums,int st,int end){
        if(st >= end){
            return;
        }
        int mid = st+(end-st)/2;
        merge2(nums,st,mid);
        merge2(nums,mid+1,end);
        merge(nums,st,end,mid);
    }

    vector<int> sortArray(vector<int>& nums) {
        merge2(nums,0,nums.size()-1);
        return nums;
    }
};