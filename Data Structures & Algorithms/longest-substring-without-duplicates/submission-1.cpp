class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        string k = "";
        int st = 0;
        int end = s.size()-1;
        int ans = 0;
        while(st <= end){
            char c = s[st];
            if(k.find(c) != string::npos){
                k.pop_back();
            }else{
                k = c+k;
                st++;
            }
            int s = k.size();
            ans= max(ans , s);
        } 
        return ans;
    }
};
