class Solution {
public:
    bool isPalindrome(string& s, int l, int r) {
        while (l < r) {
            if (s[l] != s[r]) return false;
            l++;
            r--;
        }
        return true;
    }
    bool validPalindrome(string s) {
        int n = s.size();
        int end = n-1;
        int st = 0;
        while(st < end){
            if(s[st] == s[end]){
                st++;
                end--;
            }else {
                return isPalindrome(s,st+1,end) || isPalindrome(s,st,end-1);
            }
        }
        return true;
    }
};