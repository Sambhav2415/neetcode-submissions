class Solution {
public:
    int n;
    int open,close;
    vector<string> ans;

    void solve(string &s){
        if(open == n && close == n){
            ans.push_back(s);
            return;
        }
        if(open<n){
            s = s+'(';
            open++;
            solve(s);
            int k = s.size();
            s = s.substr(0,k-1);
            open--;
        }
        if(close < open){
            s = s+')';
            close++;
            solve(s);
            int k = s.size();
            s = s.substr(0,k-1);
            close--;
        }
    }

    vector<string> generateParenthesis(int k) {
        n=k;
        open=0;
        close=0;
        string s ="";
        solve(s);
        return ans;
    }
};
