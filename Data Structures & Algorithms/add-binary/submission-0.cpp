class Solution {
public:
    string addBinary(string a, string b) {
        string s = "";
        int s1 = a.size();
        int s2 = b.size();
        int j = s1-1;
        int k = s2-1;
        int carry = 0;
        while(j >= 0 && k >= 0){
            int res = (a[j]-'0') + (b[k]-'0') + carry;
            carry = res/2;
            char c = (res%2) + '0';
            s += c;
            j--;
            k--;
        }
        while(j >=0){
            int res = (a[j]-'0') + carry;
            carry = res/2;
            char c = (res%2) + '0';
            s += c;
            j--;
        }
        while(k >= 0){
            int res = (b[k]-'0') + carry;
            carry = res/2;
            char c = (res%2) + '0';
            s += c;
            k--;
        }
        if(carry == 1){
            s += "1";
        }
        reverse(s.begin(),s.end());
        return s;
    }
};