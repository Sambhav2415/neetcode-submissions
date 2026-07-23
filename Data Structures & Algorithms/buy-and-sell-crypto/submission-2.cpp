class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int minPrice = prices[0];
        for(int num:prices){
            ans = max(ans,num-minPrice);
            minPrice = min(num,minPrice);
        }
        return ans;
    }
};
