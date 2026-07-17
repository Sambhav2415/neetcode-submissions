class Solution {
public:
    vector<vector<int>> ans;
    int size;

    void rec(int idx,int k,vector<int>&curr){
        if(curr.size() == k){
            ans.push_back(curr);
            return;
        }
        if(idx > size){
            return ;
        }
        if(curr.size()<k){
            curr.push_back(idx);
            rec(idx+1,k,curr);
            curr.pop_back();
        }else{
            return;
        }
        rec(idx+1,k,curr);
    }

    vector<vector<int>> combine(int n, int k) {
        size = n;
        vector<int> curr;
        rec(1,k,curr);
        return ans;
    }
};