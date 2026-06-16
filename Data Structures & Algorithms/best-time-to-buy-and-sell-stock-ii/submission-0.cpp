class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int prof =0;
        int currStock = prices[0];
        for(int i=1;i<prices.size();i++){
            if(prices[i]>currStock){
                prof += prices[i]-currStock;
            }
            currStock = prices[i];
        }
        return prof;
    }
};