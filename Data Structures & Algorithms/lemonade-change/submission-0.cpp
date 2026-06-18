class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0;
        int ten = 0;
        int twenty = 0;
        for(int num:bills){
            if(num == 5){
                five++;
            }else if(num == 10){
                ten++;
                if(five > 0){
                    five--;
                }else{
                    return false;
                }
            }else if(num == 20){
                twenty++;
                if(ten > 0 && five > 0){
                    five--;
                    ten--;
                }else if(five >=3){
                    five -= 3;
                }else{
                    return false;
                }
            }
        }
        return true;
    }
};