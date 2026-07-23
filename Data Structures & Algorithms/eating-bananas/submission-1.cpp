class Solution {
public:
    bool toCheck(vector<int>& piles, int h,int k){
        int reqhour = 0;
        for(int num:piles){
            reqhour += (num+k-1)/k;
        }
        return reqhour <= h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());
        while(low <= high){
            int mid = low+(high-low)/2;
            bool ans = toCheck(piles , h , mid);
            if(ans){
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return low;
    }
};
