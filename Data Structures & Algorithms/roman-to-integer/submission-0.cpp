class Solution {
public:
    int romanToInt(string s) {
        int k = s.size()-1;
        int ans = 0;
        unordered_map<char, int> roman = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };
        for(int i=0;i<=k;i++){
            char c = s[i];
            if(i == k){
                ans += roman[c];
            }else {
                if(c == 'I'){
                    if(s[i+1] == 'V'){
                        ans +=4;
                        i++;
                    }else if(s[i+1] == 'X'){
                        ans += 9;
                        i++;
                    }else {
                        ans += 1;
                    }
                }else if(c == 'X'){
                    if(s[i+1] == 'L'){
                        ans +=40;
                        i++;
                    }else if(s[i+1] == 'C'){
                        ans += 90;
                        i++;
                    }else {
                        ans += 10;
                    }
                }else if(c == 'C'){
                    if(s[i+1] == 'D'){
                        ans +=400;
                        i++;
                    }else if(s[i+1] == 'M'){
                        ans += 900;
                        i++;
                    }else {
                        ans += 100;
                    }
                }else{
                    ans += roman[c];
                }
            }
        }
        return ans;
    }
};