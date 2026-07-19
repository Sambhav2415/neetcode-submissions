class Solution {
public:
    bool check(string &s,vector<int>&dp,int idx,unordered_set<string>&st){
        if(idx == s.size()){
            return true;
        }
        if(dp[idx] != -1){
            return dp[idx];
        }
        string word = "";
        for(int i=idx;i<s.size();i++){
            word += s[i];
            if(st.count(word)){
                if(check(s,dp,i+1,st)){
                    return dp[idx]=1;
                }
            }
        }
        return dp[idx]=0;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int> dp(s.size(),-1);
        unordered_set<string> st(wordDict.begin(), wordDict.end());
        return check(s,dp,0,st);
    }
};
