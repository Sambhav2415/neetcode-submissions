class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> freq(256,0);
        int len =0;
        int left =0;
        for(int right=0;right<s.size();right++){
            while(freq[s[right]] > 0){
                freq[s[left++]]--;
            }
            len = max(len,right-left+1);
            freq[s[right]]++;
        }
        return len;
    }
};
