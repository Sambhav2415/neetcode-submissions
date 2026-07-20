class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> freq(256,0);
        int l = 0;
        int ans = 0;
        for(int i=0;i<s.size();i++){
            while(freq[s[i]] >0){
                freq[s[l]]--;
                l++;
            }
            freq[s[i]]++;
            ans = max(ans,i-l+1);
        }
        return ans;
    }
};
