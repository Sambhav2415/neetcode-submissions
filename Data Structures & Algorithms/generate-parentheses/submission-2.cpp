class Solution {
public:
    int open=0,close=0;
    vector<string> ans;
    
    void rec(int n , string& curr){
        if(curr.size() == 2*n){
            ans.push_back(curr);
            return;
        }
        if(open < n){
            open++;
            curr.push_back('(');
            rec(n,curr);
            open--;
            curr.pop_back();
        }
        if(close < open){
            close++;
            curr.push_back(')');
            rec(n,curr);
            close--;
            curr.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        string curr="";
        rec(n,curr);
        return ans;
    }
};
