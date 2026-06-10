class Solution {
public:
    double pow(double x , int n){
        if(n == 0){
            return 1.0;
        }
        double res = pow(x , n/2);
        res = res*res;
        if(n%2 != 0){
            res *= x;
        }
        return res;
    }

    double myPow(double x, int n) {
        if(n == 0){
            return 1;
        }
        if(x == 0){
            return 0;
        }
        if(x > 0){
            if(n < 0){
                return (1/pow(x,n));
            }else{
                return pow(x,-n);
            }
        }else{
            if(n%2 == 0){
                if(n < 0){
                    return (1/pow(-x,-n));
                }else{
                    return pow(-x,n);
                }
            }else{
                if(n < 0){
                    return -(1/pow(-x,-n));
                }else{
                    return -pow(-x,n);
                }
            }
        }
    }
};
