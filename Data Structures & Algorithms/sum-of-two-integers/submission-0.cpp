class Solution {
public:
    int getSum(int a, int b) {
        int prod =1;
        int sum =0;
        int carry = 0;
        for(int i=0;i<32;i++){
            int k1 = a&1;
            int k2 = b&1;
            int res = k1+k2+carry;
            int toAdd = 0;
            if(res == 0){
                carry=0;
                toAdd=0;
            }else if(res == 1){
                carry = 0;
                toAdd = 1;
            }else if(res == 2){
                carry = 1;
                toAdd = 0;
            }else if(res == 3){
                carry = 1;
                toAdd = 1;
            }

            sum += prod*toAdd;
            prod *= 2;

            a = (a>>1);
            b = (b>>1);
        }
        return sum;
    }
};
