class Solution {
public:
    bool check(vector<int>& weights, int days,int cap){
        int day = 1;
        int curr =0;
        for(int num:weights){
            if(curr+num <= cap){
                curr += num;
            }else{
                curr = num;
                day++;
            }
        }
        return day <= days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int high = 0;
        int low = weights[0];
        for(int num:weights){
            high += num; 
            low = max(low,num);
        }
        while(low <= high){
            long long mid = low+(high-low)/2;
            if(check(weights,days,mid)){
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return low;
    }
};