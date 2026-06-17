class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> inDeg(n+1,0);
        vector<int> outDeg(n+1,0);
        for(int i=0;i<trust.size();i++){
            inDeg[trust[i][1]]++;
            outDeg[trust[i][0]]++;
        }
        for(int i=1;i<=n;i++){
            if(outDeg[i]==0 && inDeg[i]==n-1){
                return i;
            }
        }
        return -1;
    }
};