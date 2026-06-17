class Solution {
public:
    vector<vector<int>> ans;

    void rec(int n, int k,vector<int> &curr,int j){
        if(curr.size() == k){
            ans.push_back(curr);
            return;
        }
        if(j > n){
            return;
        }
        rec(n,k,curr,j+1);
        if(curr.size() < k){
            curr.push_back(j);
            rec(n,k,curr,j+1);
            curr.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<int> curr;
        rec(n,k,curr,1);
        return ans;
    }
};