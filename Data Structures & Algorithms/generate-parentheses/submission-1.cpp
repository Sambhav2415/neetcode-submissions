class Solution {
public:
    int open,close;
    vector<string> ans;

    void rec(int n,string &s){
        if(open == n && close == n){
            ans.push_back(s);
            return;
        }
        if(open <n){
            s += '(';
            open++;
            rec(n,s);
            s.pop_back();
            open--;
        }
        if(close <open){
            s += ')';
            close++;
            rec(n,s);
            s.pop_back();
            close--;
        }
    }

    vector<string> generateParenthesis(int n) {
        open = 0,close =0;
        string s="";
        rec(n,s);
        return ans;
    }
};
