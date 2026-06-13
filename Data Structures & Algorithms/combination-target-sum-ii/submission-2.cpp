class Solution {
public:
    vector<vector<int>> ans;
    
    void solve(vector<int>& candidates, int target,
               int start, vector<int>& curr) {

        if (target == 0) {
            ans.push_back(curr);
            return;
        }

        for (int i = start; i < candidates.size(); i++) {

            // Skip duplicates at the same recursion level
            if (i > start && candidates[i] == candidates[i - 1])
                continue;

            if (candidates[i] > target)
                break;

            curr.push_back(candidates[i]);

            // i+1 because each element can be used at most once
            solve(candidates, target - candidates[i], i + 1, curr);

            curr.pop_back();
        }
    }


    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int>curr;
        solve(candidates,target,0,curr);
        return ans;
    }
};
