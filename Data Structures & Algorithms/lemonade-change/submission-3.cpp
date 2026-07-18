class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five=0,ten=0;
        for(int num:bills){
            if(num == 5){
                five++;
            }else if(num == 10){
                ten++;
                if(five<=0){
                    return false;
                }
                five--;
            }else{
                if(five > 0 && ten > 0){
                    ten--;
                    five--;
                }else if(five >= 3){
                    five -= 3;
                }else{
                    return false;
                }
            }
        }
        return true;
    }
};