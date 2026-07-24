class Solution {
public:
    vector<vector<int>> ans;
    void rec(int idx,vector<int>&curr , int k,int n){
        if(curr.size()==k){
            ans.push_back(curr);
            return;
        }
        if(idx > n){
            return;
        }
        if(curr.size()<k){
            curr.push_back(idx);
            rec(idx+1,curr,k,n);
            curr.pop_back();
        }
        rec(idx+1,curr,k,n);
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> curr;
        rec(1,curr,k,n);
        return ans;
    }
};