class Solution {
public:
    int n,m,k;
    bool toCheck(string&s1,string&s2,string&s3,int i,int j,int p,vector<vector<int>>&dp){
        if(i==n && j==m){
            return true;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        if(i <n && s1[i]==s3[p]){
            if(toCheck(s1,s2,s3,i+1,j,p+1,dp)){
                return dp[i][j]=true;
            }
        }
        if(j < m && s2[j]==s3[p]){
            if(toCheck(s1,s2,s3,i,j+1,p+1,dp)){
                return dp[i][j] = true;
            }
        }

        return dp[i][j]=false;
    }

    bool isInterleave(string s1, string s2, string s3) {
        n = s1.size();
        m = s2.size();
        k = s3.size();
        if(n+m !=k){
            return false;
        }
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        return toCheck(s1,s2,s3,0,0,0,dp);
    }
};
