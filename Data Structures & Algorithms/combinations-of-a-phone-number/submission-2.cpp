class Solution {
public:
    vector<string> toTake;
    vector<string> ans;

    void dfs(string &digits,string &curr,int idx){
        if(idx == digits.size()){
            toTake.push_back(curr);
            return;
        }
        string letter = ans[digits[idx]-'0'];
        for(char c:letter){
            curr.push_back(c);
            dfs(digits,curr,idx+1);
            curr.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {};
        ans.assign(10,"");
        ans[2] = "abc";
        ans[3] = "def";
        ans[4] = "ghi";
        ans[5] = "jkl";
        ans[6] = "mno";
        ans[7] = "pqrs";
        ans[8] = "tuv";
        ans[9] = "wxyz";
        string curr ="";
        dfs(digits,curr,0);
        return toTake;
    }
};
