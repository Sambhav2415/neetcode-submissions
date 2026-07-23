class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> freq(256,0);
        int l =0;
        int len = 0;
        for(int r=0;r<s.size();r++){
            while(freq[s[r]]>0){
                freq[s[l]]--;
                l++;
            }
            freq[s[r]]++;
            len = max(len,r-l+1);
        }
        return len;
    }
};
