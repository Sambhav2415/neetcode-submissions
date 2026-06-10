class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        vector<int> ans(n,0);
        int carry = 0;
        for(int i=n-1;i>=0;i--){
            if(i == n-1){
                int res = digits[i]+1;
                if(res == 10){
                    carry = 1;
                    ans[i] = 0;
                }else{
                    ans[i] = res;
                }
            }else{
                if(carry == 0){
                    ans[i] = digits[i];
                }else{
                    int res = digits[i]+1;
                    if(res == 10){
                        carry = 1;
                        ans[i] = 0;
                    }else{
                        ans[i] = res;
                        carry = 0;
                    }
                }
            }
        }
        if(carry == 1){
            vector<int> demo(n+1,1);
            for(int i=1;i<=n;i++){
                demo[i] = ans[i-1];
            }
            return demo;
        }else{
            return ans;
        }
    }
};
