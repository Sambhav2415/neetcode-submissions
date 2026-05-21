class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        string k = "";
        int st = 0 ;
        int end = s.size()-1;
        int ans = 0;
        while(st <= end){
            char c = s[st];
            if(k.find(c) != std::string::npos){
                k.erase(0, 1);
            }else{
                k += s[st];
                st++;
            }
            int s = k.size();
            ans = max(ans , s);
        }
        return ans;
    }
};
